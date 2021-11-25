import logging
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
from telegram import  InlineKeyboardButton, InlineKeyboardMarkup
import os

# Enable logging
logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.INFO)

logger = logging.getLogger(__name__)
TOKEN = os.environ["APIKEY"]
PORT = int(os.environ.get("PORT", "8443"))

# Define a few command handlers. These usually take the two arguments update and
# context. Error handlers also receive the raised TelegramError object in error.
def start(update, context):
    update.message.reply_text('/source for getting source')

def source(update, context):
    subjects_keyboard = [
                [InlineKeyboardButton("CS3334 Data Structure", callback_data='CS3334 Data Structure')]
                ]

    subjects = InlineKeyboardMarkup(keyboard)
    
    if (subjects == 'CS3334 Data Structure'):
        source_types_keyboard = [
                [InlineKeyboardButton("Weekly Coding", callback_data='Weekly Coding')]
            ]
        
        source_types = InlineKeyboardMarkup(source_types_keyboard)

        if (source_types == 'CS3334 Data Structure'):
            files_keyboard = []
            qno = [
                    '78',
                    '142',
                    '272',
                    '372',
                    '737', '738', '739',
                    '740', '741', '742', '743', '744', '745', '746', '747', '748', '749',
                    '750', '751', '752', '753', '754', '755', '756', '757', '758',
                    '814', '815', '819',
                    '820', '821', '822', '823', '824', '825', '826', '827', '828', '829',
                    '830', '832', '833', '835', '836'
                    
                ]
            for no in qno:
                files_keyboard.append[InlineKeyboardButton(no, callback_data=no)]
            reply_markup = InlineKeyboardMarkup(files_keyboard)


    update.message.reply_text('Please choose:', reply_markup='CS3334 Data Structure/' + reply_markup)

def help(update, context):
    """Send a message when the command /help is issued."""
    update.message.reply_text('/source for getting source')

def echo(update, context):
    """Echo the user message."""
    update.message.reply_text(update.message.text)

def error(update, context):
    """Log Errors caused by Updates."""
    logger.warning('Update "%s" caused error "%s"', update, context.error)

def main():
    """Start the bot."""
    # Create the Updater and pass it your bot's token.
    # Make sure to set use_context=True to use the new context based callbacks
    # Post version 12 this will no longer be necessary
    updater = Updater(TOKEN, use_context=True)

    # Get the dispatcher to register handlers
    dp = updater.dispatcher

    # on different commands - answer in Telegram
    dp.add_handler(CommandHandler("start", start, filters=~Filters.group))
    dp.add_handler(CommandHandler("help", help))
    dp.add_handler(CommandHandler("source", source, filters=~Filters.group))

    # on noncommand i.e message - echo the message on Telegram
    dp.add_handler(MessageHandler(Filters.text, echo))

    # log all errors
    dp.add_error_handler(error)

    # Start the Bot
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
