from telegram.ext import Updater, CommandHandler, Filters, MessageHandler

import os
from dotenv import load_dotenv

from commands.hub import *
from conversations.hub import *
from messagehandlers.hub import *
from modules.utils import *
from modules.tginstatracker import insta_tracker

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
    updater = Updater(TOKEN, use_context=True, workers=6)
    
    dp = updater.dispatcher

    # Command handler
    dp.add_handler(CommandHandler("help", help))
    dp.add_handler(CommandHandler("launchbot", launchbot))
    dp.add_handler(CommandHandler("updatelog", updatelog))
    dp.add_handler(CommandHandler('geguide', geguide))
    dp.add_handler(CommandHandler('wantpokemon', wantpokemon))
    dp.add_handler(CommandHandler('my903', my903))
    dp.add_handler(CommandHandler('crypto', crypto))
    dp.add_handler(CommandHandler('css', css))
    dp.add_handler(CommandHandler('su', su))
    dp.add_handler(CommandHandler('cityuinfo', cityuinfo))
    dp.add_handler(CommandHandler('cbc', cbc))
    dp.add_handler(CommandHandler('edb', edb))
    
    dp.add_handler(CommandHandler("start", start, filters=~Filters.group))
    dp.add_handler(CommandHandler('pin', pin, filters=~Filters.group))

    # Message handler
    dp.add_handler(MessageHandler(Filters.status_update.new_chat_members, welcome))
    dp.add_handler(MessageHandler(Filters.status_update.left_chat_member, remove_member))

    # Conversation handler
    dp.add_handler(source_conv_handler)
    dp.add_handler(new_poll_conv_handler)
    dp.add_handler(poll_conv_handler)
    dp.add_handler(result_conv_handler)
    dp.add_handler(new_poll_conv_handler)

    # Error handler
    dp.add_error_handler(error)

    # Scheduled tasks
    if not APP_ENV_IS_TEST:
        j = updater.job_queue
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
help - show all command
launchbot - launch the bot and get some help
updatelog - get update log
geguide - get quick link to ge guide
wantpokemon - send you a pokemon!
my903 - check out this week's top 10 songs
crypto - check crypto price
css - get our society's latest ig post
su - get student union's latest ig post
cityuinfo - get hkcityu.info latest ig post
cbc - get SU City Broadcasting Channel latest ig post
edb - get SU Editorial Board latest ig post
'''
