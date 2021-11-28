import requests
from telegram import  InlineKeyboardButton, InlineKeyboardMarkup
from telegram.ext import  CommandHandler, Filters, CallbackQueryHandler, ConversationHandler
from module.utils import end

Subject, Type, File = range(3)


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
            # '185',
            '372',
            # '438',
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
    path = "https://github.com/laub1199/cityu-cs-tg-bot/raw/master/source/"
    document = path + str(query.data)

    r = requests.get(document)

    filename = 'untitled.txt'

    if ('Weekly Coding' in query.data):
        filename = query.data.split('/Weekly Coding/')[1]

    query.edit_message_text(text="Selected option: {}".format(filename))

    context.bot.sendDocument(chat_id=query.message.chat.id, document=r.content, filename=filename)
    print(document)

source_conv_handler = ConversationHandler(
        entry_points=[CommandHandler('source', source, filters=~Filters.group)],
        states={
            Subject: [CallbackQueryHandler(source_subject_query)],
            Type: [CallbackQueryHandler(source_type_query)],
            File: [CallbackQueryHandler(fileHandler)]
        },
        fallbacks=[CommandHandler('end', end)],
    )