import random
from telegram.utils import helpers
from telegram import InlineKeyboardButton, InlineKeyboardMarkup


def start(update, context):
    update.message.reply_text('/source for getting source')


def help(update, context):
    url = helpers.create_deep_linked_url(context.bot.get_me().username, 'city-cs')
    keyboard = InlineKeyboardMarkup.from_button(
        InlineKeyboardButton(text='Get Resource here!', url=url)
    )

    update.message.reply_text("Heyyy", reply_markup=keyboard)


def updatelog(update, context):
    chat_id = update.message.chat.id
    #txt = open("update_log.txt", "r").read()
    with open("update_log.txt") as myfile:
        text = ''.join(str(s) for s in [next(myfile) for x in range(8)])
    context.bot.sendMessage(chat_id=chat_id, text=text, parse_mode='HTML')


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


def wantpokemon(update, context):
    poke_id = str(random.randrange(897) + 1).zfill(3)
    photo_url = 'https://assets.pokemon.com/assets/cms2/img/pokedex/detail/{}.png'.format(poke_id)
    context.bot.send_photo(chat_id=update.message.chat.id, photo=photo_url)
