import requests
from telegram import InlineKeyboardButton, InlineKeyboardMarkup, ForceReply
from telegram.ext import CommandHandler, Filters, CallbackQueryHandler, ConversationHandler, MessageHandler
from modules.utils import end

AddPoll, AddChoice = range(2)

active_poll = {
    'by_user_id': None,
    'by_user_username': None,
    'question': None,
    'choices': [],
    'voted': [],
    'is_active': False
}

empty_poll = {
    'by_user_id': None,
    'by_user_username': None,
    'question': None,
    'choices': [],
    'voted': [],
    'is_active': False
}


def new_poll(update, context):
    global active_poll
    if active_poll['is_active']:
        context.bot.sendMessage(chat_id=update.message.chat_id, text='有poll開緊 完左poll先啦！\n /poll - 投票\n /endpoll - 終止投票')
        return ConversationHandler.END
    active_poll['by_user_id'] = update.message.from_user.id
    active_poll['by_user_username'] = update.message.from_user.username
    update.message.reply_text("話我知你嘅問題 我再幫你開個poll！", reply_markup=ForceReply())
    return AddPoll


def add_poll(update, context):
    global active_poll
    active_poll['question'] = update.message.text
    return ConversationHandler.END


def poll(update, context):
    global active_poll
    if active_poll['is_active']:
        context.bot.sendMessage(chat_id=update.message.chat_id, text='冇poll喎, /poll 開個新poll先啦！')
        return ConversationHandler.END


def result(update, context):
    global active_poll
    if active_poll['is_active']:
        context.bot.sendMessage(chat_id=update.message.chat_id, text='冇poll喎, /poll 開個新poll先啦！')
        return ConversationHandler.END


def end_poll(update, context):
    global active_poll
    if active_poll['is_active']:
        context.bot.sendMessage(chat_id=update.message.chat_id, text='冇poll喎, /poll 開個新poll先啦！')
        return ConversationHandler.END


new_poll_conv_handler = ConversationHandler(
    entry_points=[CommandHandler('newpoll', new_poll, filters=~Filters.private)],
    states={
        AddPoll: [MessageHandler(Filters.text, add_poll)]
    },
    fallbacks=[CommandHandler('end', end)]
)

poll_conv_handler = ConversationHandler(
    entry_points=[CommandHandler('poll', poll, filters=~Filters.private)],
    states={},
    fallbacks=[CommandHandler('end', end)]
)

result_conv_handler = ConversationHandler(
    entry_points=[CommandHandler('result', result, filters=~Filters.private)],
    states={},
    fallbacks=[CommandHandler('end', end)]
)

end_poll_conv_handler = ConversationHandler(
    entry_points=[CommandHandler('endpoll', end_poll, filters=~Filters.private)],
    states={},
    fallbacks=[CommandHandler('end', end)]
)
