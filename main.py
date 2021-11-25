import logging
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters, CallbackQueryHandler, ConversationHandler, CallbackContext
from telegram import  InlineKeyboardButton, InlineKeyboardMarkup, Update
import os
import requests

# Enable logging
logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.INFO)

logger = logging.getLogger(__name__)
TOKEN = os.environ["APIKEY"]
PORT = int(os.environ.get("PORT", "8443"))

Subject, Type, File = range(3)

# Define a few command handlers. These usually take the two arguments update and
# context. Error handlers also receive the raised TelegramError object in error.
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
            '372',
            '737', '738', '739',
            '740', '741', '742', '743', '744', '745', '746', '747', '748', '749',
            '750', '751', '752', '753', '754', '755', '756', '757', '758',
            '815', '819',
            '820', '821', '822', '823', '824', '825', '826', '827', '828', '829',
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
    """Send a message when the command /help is issued."""
    update.message.reply_text('/source for getting source')

def echo(update, context):
    """Echo the user message."""
    update.message.reply_text(update.message.text)

def error(update, context):
    """Log Errors caused by Updates."""
    logger.warning('Update "%s" caused error "%s"', update, context.error)

def end():
    query = update.callback_query
    query.answer()
    query.edit_message_text(text="See you next time!")
    return ConversationHandler.END

def main():
    """Start the bot."""
    # Create the Updater and pass it your bot's token.
    # Make sure to set use_context=True to use the new context based callbacks
    # Post version 12 this will no longer be necessary
    updater = Updater(TOKEN, use_context=True)

    # Get the dispatcher to register handlers
    dp = updater.dispatcher

    # on different commands - answer in Telegram
    dp.add_handler(CommandHandler("start", start, filters=~Filters.chat_type.group))
    dp.add_handler(CommandHandler("help", help))

    # on noncommand i.e message - echo the message on Telegram
    # dp.add_handler(MessageHandler(Filters.text, echo))

    # log all errors
    dp.add_error_handler(error)
    
    source_conv_handler = ConversationHandler(
        entry_points=[CommandHandler('source', source, filters=~Filters.chat_type.group)],
        states={
            Subject: [CallbackQueryHandler(source_subject_query)],
            Type: [CallbackQueryHandler(source_type_query)],
            File: [CallbackQueryHandler(fileHandler)]
        },
        fallbacks=[CommandHandler('end', end)],
    )

    dp.add_handler(source_conv_handler)


    # Start the Bot
    # updater.start_polling()
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
