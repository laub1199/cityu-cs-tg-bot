import telegram
from time import sleep
import os
from telegram.ext import Updater

TOKEN = os.environ["APIKEY"]
PORT = int(os.environ.get('PORT', 5000))

def start(update, context):
    update.message.reply_text('/source for Getting the source')

def main():
    updater = Updater(TOKEN, use_context=True)
    dp = dp = updater.dispatcher

    dp.add_handler(CommandHandler("start", start,filters=~Filters.group))

    updater.start_polling()
    
if __name__ == "__main__":
    main()
