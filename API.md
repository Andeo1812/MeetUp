# API проекта MeetUp

Коммуникация в работе приложения осуществляетя по JSON, библиотека nlohman::json.

## 1. База

### `Registration`

**_Response:_**
```c
{"registration":{"nickname":"Sasha","password":"123456asd64569898989"}}
```

**_Answer:_**
```c
{"registration":{"id":"56"}}
```

Порядок работы:

Клиент присылает никнейм и пароль нового пользователя, которые размещаются в базе, вовращает id нового юсера в базе.

### `Autorization`

**_Response:_**
```c
{"authentication":{"nickname":"Sasha","password":"123456asd64569898989"}}
```

**_Answer:_**
```c
{"authentication":{"id":"56"}}
```

Порядок работы:

Аналогично регистрации принимает ник и пароль, при соответствии данной комбинации отдает id.

## 2. Events

### `Add`

**_Response:_**
```c
{"add_event":[{"name":"breakfast","date":"01-06-2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00", "user_id":"56"}]}
```

**_Answer:_**
```c
{"add_event":{"id":"56"}}
```

Порядок работы:

Клиент присылает данные мероприятия, отдаем ip ивента в базе. Все поля должны быть заполнены (на текущий момент).

### `Rewrite`

**_Response:_**
```c
{"rewrite_event":[{"id":"56", "name":"breakfast","event_date":"01-06-2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"}]}
```

**_Answer:_**
```c
{"write_event":"OK"}
```

Порядок работы:

Изменяет **уже существующее** мероприятие в базе. Все поля обязательны (на текущий момент).

### `Delete`

**_Response:_**
```c
{"delete_event":[{"id":"56"}]}
```

**_Answer:_**
```c
{"delete_event":"OK"}
```

Порядок работы:

Изменяет **уже существующее** мероприятие в базе. Все поля обязательны (на текущий момент).

## 3. Contacts

### `Add`

**_Response:_**
```c
{"add_contact":{"id":"56","contacts":["Ibragim"]}}
```

**_Answer:_**
```c
{"add_contact":"OK"}
```

Порядок работы:

По нику добавляем друга к пользователю. Операция двунаправленная.

### `Delete`

**_Response:_**
```c
delete_friend: {"delete_friend":{"id":"56","contacts":["Ibragim"]}}
```

**_Answer:_**
```c
{"delete_friend":"OK"}
```

Порядок работы:

По нику удаляем друга к пользователю. Операция двунаправленная.

## 4. Group. Base

### `Create group`

**_Response:_**
```c
{"create_group":{"title":"Texnosrac", "description":"2132", "members":["Ibragim"]}}
```

**_Answer:_**
```c
{"create_group":{"id":"56"}}
```

Порядок работы:

Пользователь создает группу с полями имени, описания. И его ник идет как первый участник.

### `Rewrite`

**_Response:_**
```c
{"rewrite_group":{"id":"56","title":"Texnosrac", "description":"2132"}}
```

**_Answer:_**
```c
{"rewrite_group":"OK"}
```

Порядок работы:

Изменяет данные группы. Все поля обязательны (на текущий момент).

### `Delete`

**_Response:_**
```c
{"delete_group":{"id":"23"}}
```

**_Answer:_**
```c
{"delete_group":"OK"}
```

Порядок работы:

По id удаляем группу.

### `Get members`

**_Response:_**
```c
{"get_group_members":{"id":"56"}}
```

**_Answer:_**
```c
{"get_group_members":[{"members":["mars1234","qwerty"]}]}
```

Порядок работы:

По id отдает всех участников группы.

## 5. Group. Management

### `Add user`

**_Response:_**
```c
{"invite":{"id":"65", "members":["mars1234"]}}
```

**_Answer:_**
```c
{"invite":"OK"}
```

Порядок работы:

Любой пользователь группы может добавлять новых участников в группу по нику.

### `Rewrite`

**_Response:_**
```c
{"kick":{"id":"56", "members":["Sasha"]}}
```

**_Answer:_**
```c
{"kick":"OK"}
```

Порядок работы:

По нику удалить (на данный момент работаем над ролями).

## 6. Synchronization

### `Get events`

**_Response:_**
```c
{"get_events":[{"id":"56", "date":"yyyy-mm-dd"}]}
```

**_Answer:_**
```c
{"get_events":[{"description":"breakfast", "time_begin":"10:00", "time_end":"10:45"}, {"description":"lansh", "time_begin":"19:00", "time_end":"20:00"}]}
```

Порядок работы:

Отдает все мероприятия пользователя по его id по дате за день.

### `Get contacts`

**_Response:_**
```c
{"get_contacts":{"id":"56"}}
```

**_Answer:_**
```c
{"get_contacts":["Misha","Maxim"]}
```

Порядок работы:

Отдает все контанкты юзера по его id.

### `Get groups`

**_Response:_**
```c
{"get_groups":{"members":["Sasha"]}}
```

**_Answer:_**
```c
{"get_groups":[{"id":"48","title":"111111111111111111"},{"group_id":"2","title":"group techno"},{"group_id":"4","title":"qqaa"},{"description":"213131313231231323131123","group_id":"1","title":"qqqqqqqqqq"},{"group_id":"3","title":"qwe1"},{"group_id":"11","title":"sdvsdv"}]}
```

Порядок работы:

Отдает все данных всех групп пользователя по его нику.

## 7. Personal data

### `Write personal`

**_Response:_**
```c
{"write_personal":{"id":"8", "first_name":"Bogdan", "surname":"Kazimirov", "age":"21", "phone_number":"+79017453550", "status":"asdas", "label":"1asd", "description":"MT11-72", "email":"bs@mt11.su"}}
```

**_Answer:_**
```c
{"write_personal":"OK"}
```

Порядок работы:

Эти данные для разрабов и пользователей в приватном порядке. При регистрации создается пустая запись. Этот затирает данные (все поля необходимы)

### `Get presonal data`

**_Response:_**
```c
{"get_personal":{"id":"1"}}
```

**_Answer:_**
```c
{"get_personal":{"id":"1", "first_name":"Bogdan", "surname":"Kazimirov", "age":"21", "phone_number":"+79017453550", "status":"WTF?", "label": "null", "description":"MT11-72", "email":"bs@mt11.su"}}
```

Порядок работы:

Отдает все данные пользователю.

## 7. General data

### `Write general data`

**_Response:_**
```c
{"write_general":{"id":"8", "status":"asdas", "tags":"1asd", "description":"MT11-72"}}
```

**_Answer:_**
```c
"write_general":"OK"}
```

Порядок работы:

Глобальные публичные данные для просмотра. По id позволяет отредачить. По аналогии с персональными. При регистрации создается пустая запись.

### `Get general data`

**_Response:_**
```c
{"get_general":{"id":"1"}}
```

**_Answer:_**
```c
{"get_general":{"id":"8", "status":"asdas", "label":"1asd", "description":"MT11-72"}}
```

Порядок работы:

Отдает все глобальные данные пользователя по id по аналогии с персональными.

## 8. Address data

### `Write address`

**_Response:_**
```c
{"write_address":{"id":"1", "building":"1", "housing":"1", "street":"Bolshaya Voskresenskaya","city":"Krasnogorsk","district":"Krasnogorskiy","index":"143430", "country":"Russia"}}
```

**_Answer:_**
```c
{"write_address":"OK"}
```

Порядок работы:

Личные данные. Адрес предназначен для только для разрабов. По id затирает данные. При регистрации создается пустая запись.

### `Get address`

**_Response:_**
```c
{"get_address":{"id":"1"}}
```

**_Answer:_**
```c
{"get_address":{"id":"1", "building":"1", "housing":"1", "street":"Bolshaya Voskresenskaya","city":"Krasnogorsk","district":"Krasnogorskiy","index":"143430", "country":"Russia"}}
```

Порядок работы:

Отдает адресс пользователю, который его же и вызвал.

## 9. MeetUp

### `Get MeetUp`

**_Response:_**
```c
{"get_meetup":{"date":"2022-01-26", "id":"61"}}
```

**_Answer:_**
```c
{"get_meetup":[{"time_begin":"00:00","time_end":"00:30"},{"time_begin":"20:15","time_end":"23:30"}]}
```

Порядок работы:

Главная фича проекта. По id группы и дате отдает все возможные свободные одновременно для всех промежутки времени. 
    