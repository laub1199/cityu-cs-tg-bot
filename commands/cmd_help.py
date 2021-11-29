from telegram.utils import helpers
from telegram import InlineKeyboardButton, InlineKeyboardMarkup


def help(update, context):
    url = helpers.create_deep_linked_url(context.bot.get_me().username, 'city-cs')
    keyboard = InlineKeyboardMarkup.from_button(
        InlineKeyboardButton(text='Get Resource here!', url=url)
    )

    update.message.reply_text("Heyyy", reply_markup=keyboard)
