import pyttsx3
import datetime
day_time = str(datetime.datetime.now().time())

engine = pyttsx3.init()
engine.say('Добрый день.')
engine.runAndWait()
while True:
    human_say = input('')
    if human_say.lower() == 'привет' :
        engine.say('Привет хозяин')
        engine.runAndWait()
    if human_say.lower() == 'повтори':
        engine.say('Что именно?')
        engine.runAndWait()
        i = 1
        while i == 1:
            human_say = input()
            if ('стой' in human_say.lower() or 'стоп' in human_say.lower() or 'остановись' in human_say.lower() ) and '/' in human_say.lower():
                i = 0
                break
            engine.say(human_say)
            engine.runAndWait()
    if 'время' in human_say.lower() and '/' in human_say.lower():
        engine.say(day_time[:6])
        engine.runAndWait()
    if 'умеешь' in human_say.lower() or 'можешь' in human_say.lower() and '/' in human_say.lower():
        engine.say('Пока что я могу подсказать вам время, поприветствовать вас, и повторять за вами')
        engine.runAndWait()