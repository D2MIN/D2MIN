import openpyxl
import random

#Настройка для работы с эксель файлом
name = input('Пожалуйста введите название файла ')
name = name+'.xlsx'
excel_file = openpyxl.load_workbook(name)
name_list = input('Пожалуйста введите из какого листа в файле читать информацию ')
employees_sheet = excel_file[name_list]
currently_active_sheet = excel_file.active
cell_obj = employees_sheet.cell(row=1, column=1)

# Мой код
list = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y','Z']
n1 = int(input('Пожалуйста введите колличество колонок '))
n2 = int(input('Пожалуйста введите колличество строк '))
list_name = []
top_list_name = []
top_data = ''
for u in range(0,n1):
    for i in range(2,n2+1):
        data = (employees_sheet[list[u]+str(i)].value)
        top_data += str(data)
        list_name.append(top_data)
        top_data = ''
    top_list_name.append(list_name)
    list_name = []

n = 0
count = int(input('колько фраз вы хотите ? '))
print('\n')
st = ''
while n != count:
    for i in top_list_name:
        st += (i[random.randint(0,len(i)-1)]+' ')
    st += '\n\n'
    n += 1
print(st)

end = input('Для завершении работы программы нажмите Enter')