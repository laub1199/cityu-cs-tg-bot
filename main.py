from telegram.ext import Updater, CommandHandler, Filters

import os
from dotenv import load_dotenv

from module.command import *
from module.utils import *
from module.conv_source import source_conv_handler
from module.tginstatracker import InstaTracker



load_dotenv()

APP_ENV_IS_TEST = True if os.environ.get("APP_ENV") == 'test' else False
TOKEN = os.environ.get("TOKEN")
PORT = int(os.environ.get("PORT", "8443"))

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

    # Command handler
    dp.add_handler(CommandHandler("help", help))
    dp.add_handler(CommandHandler("updatelog", updatelog))
    dp.add_handler(CommandHandler('geguide', geguide))
    dp.add_handler(CommandHandler('wantpokemon', wantpokemon))
    
    dp.add_handler(CommandHandler("start", start, filters=~Filters.group))

    # Conversation handler
    dp.add_handler(source_conv_handler)

    # Error handler
    dp.add_error_handler(error)

    # scheduled task
    j = updater.job_queue

    group_list = [-1001338851560] if APP_ENV_IS_TEST else [-1001278050153]
    target_username_list = ['thestandnews', 'nba'] if APP_ENV_IS_TEST else ['cityusu', 'cityucss_nebulae', 'cityusu_welfare']
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

    updater.idle()

if __name__ == '__main__':
    main()

'''
help - launch the bot and get some help
updatelog - get update log
geguide - get quick link to ge guide
'''
