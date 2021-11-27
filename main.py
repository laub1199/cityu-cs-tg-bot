import logging
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters, CallbackQueryHandler, ConversationHandler, CallbackContext
from telegram import  InlineKeyboardButton, InlineKeyboardMarkup, Update
from telegram.utils import helpers
import os
import requests
from module.tginstatracker import InstaTracker
from dotenv import load_dotenv
load_dotenv()

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.INFO)

logger = logging.getLogger(__name__)
APP_ENV_IS_TEST = True if os.environ.get("APP_ENV") == 'test' else False
TOKEN = os.environ.get("TOKEN")
PORT = int(os.environ.get("PORT", "8443"))

Subject, Type, File = range(3)

def start(update, context):
    update.message.reply_text('/source for getting source')

def source(update, context):
    keyboard = [
                [InlineKeyboardButton("CS3334 Data Structure", callback_data='CS3334 Data Structure')]
                ]

    reply_markup = InlineKeyboardMarkup(keyboard)
    text = 'Select a subject:'

    context.bot.send_message(chat_id=update.effective_chat.id, reply_markup=reply_markup, text=text)
    
    return Subject

def source_subject_query(update, context):
    query = update.callback_query
    query.answer()
    
    if (query.data == 'CS3334 Data Structure'):
        keyboard = [
                [InlineKeyboardButton("Weekly Coding", callback_data='CS3334 Data Structure/Weekly Coding')]
            ]
        
        reply_markup = InlineKeyboardMarkup(keyboard)
        text = 'Select a source type'
        
        query.edit_message_text(reply_markup=reply_markup, text=text)

    return Type    

def source_type_query(update, context):
    query = update.callback_query
    query.answer()
    keyboard = []
    if (query.data == 'CS3334 Data Structure/Weekly Coding'):
        qno = [
            '78',
            '142',
            #'185',
            '372',
            #'438',
            '737', '738', '739',
            '740', '741', '742', '743', '744', '745', '746', '747', '748', '749',
            '750', '751', '752', '753', '754', '755', '756', '757', '758',
            '815', '819',
            '821', '822', '823', '824', '825', '826', '827', '829',
            '830', '832', '835', '836'
            ]
        for no in qno:
            keyboard += [[InlineKeyboardButton(no, callback_data='CS3334 Data Structure/Weekly Coding/' + no + '.cpp')]]
    reply_markup = InlineKeyboardMarkup(keyboard)
    text = 'Please select'
    
    query.edit_message_text(reply_markup=reply_markup, text=text)

    return File

def fileHandler(update, context):
    query = update.callback_query
    update.callback_query.answer()
    path="https://github.com/laub1199/cityu-cs-tg-bot/raw/master/source/"
    document = path + str(query.data)
    
    r = requests.get(document)

    filename = 'untitled.txt'

    if('Weekly Coding' in query.data):
        filename = query.data.split('/Weekly Coding/')[1]
        
    query.edit_message_text(text="Selected option: {}".format(filename))
    
    context.bot.sendDocument(chat_id=query.message.chat.id, document=r.content, filename=filename)
    print(document)

def help(update, context):
    url = helpers.create_deep_linked_url(context.bot.get_me().username, 'city-cs')
    keyboard = InlineKeyboardMarkup.from_button(
        InlineKeyboardButton(text='Get Resource here!', url=url)
    )

    update.message.reply_text("Heyyy", reply_markup=keyboard)

def updatelog(update, context):
    chat_id=update.message.chat.id
    txt = open("update_log.txt", "r").read()
    context.bot.sendMessage(chat_id=chat_id,text = txt, parse_mode= 'HTML')

def geguide(update, context):
    if (not context.args):
        update.message.reply_text("Course code missing, e.g. /geguide ge1401")
    elif (len(context.args) > 1):
        update.message.reply_text("Only 1 couse code is required, e.g. /geguide ge1401")
    else:
        url = 'http://cityuge.swiftzer.net/courses/' + str(context.args[0]).lower()
        text = 'Check out ' + str(context.args[0]).upper() + '!'
        keyboard = InlineKeyboardMarkup.from_button(
            InlineKeyboardButton(text=text, url=url)
        )

        update.message.reply_text("Quick link!", reply_markup=keyboard)
        
def error(update, context):
    """Log Errors caused by Updates."""
    logger.warning('Update "%s" caused error "%s"', update, context.error)

def end(update):
    query = update.callback_query
    query.answer()
    query.edit_message_text(text="See you next time!")
    return ConversationHandler.END

def main():
    print('=======================================================')
    if APP_ENV_IS_TEST:
        print('Testing Environment...')
    else:
        print('Product Environment...')
    print('=======================================================')
    """Start the bot."""
    updater = Updater(TOKEN, use_context=True)
    
    dp = updater.dispatcher

    dp.add_handler(CommandHandler("help", help))
    dp.add_handler(CommandHandler("updatelog", updatelog))
    dp.add_handler(CommandHandler('geguide', geguide))
    
    dp.add_handler(CommandHandler("start", start, filters=~Filters.group))
    
    source_conv_handler = ConversationHandler(
        entry_points=[CommandHandler('source', source, filters=~Filters.group)],
        states={
            Subject: [CallbackQueryHandler(source_subject_query)],
            Type: [CallbackQueryHandler(source_type_query)],
            File: [CallbackQueryHandler(fileHandler)]
        },
        fallbacks=[CommandHandler('end', end)],
    )

    dp.add_handler(source_conv_handler)

    dp.add_error_handler(error)

    # scheduled task
    j = updater.job_queue

    group_list = [-1001338851560] if APP_ENV_IS_TEST else [-1001278050153]
    target_username_list = ['thestandnews', 'nba'] if APP_ENV_IS_TEST else ['cityusu', 'cityucss_nebulae']
    insta_tracker = InstaTracker(
        os.environ.get("INSTA_TRACK_USERNAME"),
        os.environ.get("INSTA_TRACK_PASSWORD"),
        group_list=group_list,
        target_username_list=target_username_list
    )
    j.run_repeating(insta_tracker.insta_track, 300, job_kwargs={'max_instances': 20})
    # Start the Bot
    if APP_ENV_IS_TEST:
        updater.start_polling()
    else:
        updater.start_webhook(listen="0.0.0.0",
                             port=int(PORT),
                             url_path=TOKEN)
        updater.bot.setWebhook('https://citycs-tg-bot.herokuapp.com/' + TOKEN)

    # Run the bot until you press Ctrl-C or the process receives SIGINT,
    # SIGTERM or SIGABRT. This should be used most of the time, since
    # start_polling() is non-blocking and will stop the bot gracefully.
    updater.idle()

if __name__ == '__main__':
    main()

'''
help - launch the bot and get some help
updatelog - get update log
geguide - get quick link to ge guide
'''
