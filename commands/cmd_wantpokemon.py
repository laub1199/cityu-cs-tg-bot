import pokepy
import random


def wantpokemon(update, context):
    client = pokepy.V2Client()
    poke_id = random.randrange(897) + 1
    poke = client.get_pokemon(poke_id)
    indefinite = 'an' if poke.types[0].type.name in ['a', 'e', 'i', 'o', 'u'] else 'a'
    text = 'This is {},\n {} '.format(poke.name, indefinite)
    for index, types in enumerate(poke.types):
        if index > 0:
            text += ' & '
        text += types.type.name
    text += ' pokémon!'
    poke_id = str(poke_id).zfill(3)
    photo_url = 'https://assets.pokemon.com/assets/cms2/img/pokedex/detail/{}.png'.format(poke_id)
    context.bot.send_photo(chat_id=update.message.chat.id, photo=photo_url, caption=text)
