from gtts import gTTS
from tqdm import tqdm
from time import sleep

file = open('translete.txt', 'r' ,encoding='utf-8')
data = file.readlines()

print('Запуск программы... \n')
for i in tqdm( range( 100 ) ):
    sleep(0.05)

text = ''
for i in data:
    i = i.replace('\n',' ')
    text += i

print('\nЗаписываю файл... \nНе выключайте программу пока файл не сохранится')

tts = gTTS(text = text, lang='ru')
tts.save('file.mp3')

print("\033[32m{}".format('\nФайл сохранён'))
print(input(''))
file.close()
