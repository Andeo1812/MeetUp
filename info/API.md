# API проекта MeetUp

Коммуникация в работе приложения осуществляетя по JSON, библиотека nlohman::json.

## 1. База

### `Registration STATUS : complited`

**_Response:_**
```c
{"registration":{"nickname":"Sasha","password":"123456asd64569898989"}}
```

**_Answer:_**
```c
{"registration":{"user_id":"56"}}
```

Порядок работы:

Клиент присылает никнейм и пароль нового пользователя, которые размещаются в базе, вовращает id нового юсера в базе.

### `Autorization STATUS : complited`

**_Response:_**
```c
{"authentication":{"nickname":"Sasha","password":"123456asd64569898989"}}
```

**_Answer:_**
```c
{"authentication":{"user_id":"56"}}
```

Порядок работы:

Аналогично регистрации принимает ник и пароль, при соответствии данной комбинации отдает id.

### `Rm STATUS : complited`

**_Response:_**
```c
{"rm_user":{"user_id":"56"}}
```

**_Answer:_**
```c
{"rm_user":"OK"}
```

Порядок работы:

По id удаляем юсера.

## 2. Events

### `Add STATUS : complited`

**_Response:_**
```c
{"add_event":[{"event_name":"breakfast","event_date":"01-06-2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00", "user_id":"56"}]}
```

**_Answer:_**
```c
{"add_event":{"event_id":"56"}}
```

Порядок работы:

Клиент присылает данные мероприятия, отдаем ip ивента в базе. Все поля должны быть заполнены (на текущий момент).

### `Rewrite`

**_Response:_**
```c
{"rewrite_event":[{"event_id":"56", "event_name":"breakfast","event_date":"01-06-2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"}]}
```

**_Answer:_**
```c
{"write_event":"OK"}
```

Порядок работы:

Изменяет **уже существующее** мероприятие в базе. Все поля обязательны (на текущий момент).

### `Rm STATUS : complited`

**_Response:_**
```c
{"rm_event":[{"event_id":"56"}]}
```

**_Answer:_**
```c
{"rm_event":"OK"}
```

Порядок работы:

Изменяет **уже существующее** мероприятие в базе. Все поля обязательны (на текущий момент).

### `Get events STATUS : complited`

**_Response:_**
```c
{"get_events":[{"user_id":"56", "event_date":"yyyy-mm-dd"}]}
```

**_Answer:_**
```c
{"get_events":[{"description":"breakfast", "time_begin":"10:00", "time_end":"10:45"}, {"description":"lansh", "time_begin":"19:00", "time_end":"20:00"}]}
```

Порядок работы:

Отдает все мероприятия пользователя по его id по дате за день.

## 3. Contacts

### `Add STATUS : complited`

**_Response:_**
```c
{"add_contact":{"user_id":"56","contacts":["Ibragim"]}}
```

**_Answer:_**
```c
{"add_contact":"OK"}
```

Порядок работы:

По нику добавляем друга к пользователю. Операция двунаправленная.

### `Rm STATUS : complited`

**_Response:_**
```c
{"rm_contact":{"user_id":"56","contacts":["Ibragim"]}}
```

**_Answer:_**
```c
{"rm_contact":"OK"}
```

Порядок работы:

По нику удаляем друга к пользователю. Операция двунаправленная.

### `Get contacts STATUS : complited`

**_Response:_**
```c
{"left":5,"right":10,"get_contacts":{"user_id":"56"}}
```

**_Answer:_**
```c
{"left":5,"right":10,"get_contacts":["Misha","Maxim"]}
```

Порядок работы:

Отдает конкретные контакты юзера по его id.

## 4. Group. Base

### `Create group STATUS : complited`

**_Response:_**
```c
{"create_group":[{"description":"2132", "members":["Ibragim"], "title":"Texno"}]}
```

**_Answer:_**
```c
{"create_group":{"group_id":"56"}}
```

Порядок работы:

Пользователь создает группу с полями имени, описания. И его ник идет как первый участник.

### `Rewrite`

**_Response:_**
```c
{"rewrite_group":[{"description":"2132", "members":["Ibragim"], "title":"Texno"}]}
```

**_Answer:_**
```c
{"rewrite_group":"OK"}
```

Порядок работы:

Изменяет данные группы. Все поля обязательны (на текущий момент).

### `Rm STATUS : complited`

**_Response:_**
```c
{"rm_group":[{"group_id":"23"}]}
```

**_Answer:_**
```c
{"rm_group":"OK"}
```

Порядок работы:

По id удаляем группу.

### `Get members STATUS : complited`

**_Response:_**
```c
{"get_group_members":[{"group_id":"56"}]}
```

**_Answer:_**
```c
{"get_group_members":[{"members":["mars1234","qwerty"]}]}
```

Порядок работы:

По id отдает всех участников группы.

### `Get groups STATUS : complited`

**_Response:_**
```c
{"get_groups":[{"user_id":"32"}],"left":5,"right":10}
```

**_Answer:_**
```c
{"left":5,"right":10,"get_groups":[{"group_id":"48","title":"111111111111111111"},{"group_id":"2","title":"group techno"},{"group_id":"4","title":"qqaa"},{"description":"213131313231231323131123","group_id":"1","title":"qqqqqqqqqq"},{"group_id":"3","title":"qwe1"},{"group_id":"11","title":"sdvsdv"}]}
```

Порядок работы:

Отдает конекртные группы пользователя по его нику или ip.

## 5. Group. Management

### `Add user STATUS : complited`

**_Response:_**
```c
{"invite":[{"group_id":"65", "members":["mars1234"]}]}
```

**_Answer:_**
```c
{"invite":"OK"}
```

Порядок работы:

Любой пользователь группы может добавлять новых участников в группу по нику.

### `Rm user STATUS : complited`

**_Response:_**
```c
{"kick":[{"id":"group_id", "members":["Sasha"]}]}
```

**_Answer:_**
```c
{"kick":"OK"}
```

Порядок работы:

По нику удалить (на данный момент работаем над ролями).

## 6. Personal data

### `Write personal`

**_Response:_**
```c
{"write_personal":{"user_id":"8", "name":"Bogdan", "surname":"Kazimirov", "date_birth":"21", "phone_number":"+79017453550", "email":"bs@mt11.su"}}
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
{"get_personal":{"user_id":"1"}}
```

**_Answer:_**
```c
{"get_personal":{"user_id":"1", "name":"Bogdan", "surname":"Kazimirov", "date_birth":"2000-01-01", "phone_number":"+79017453550", "email":"bs@mt11.su"}}
```

Порядок работы:

Отдает все данные пользователю.

## 7. General data

### `Write general data`

**_Response:_**
```c
{"write_general":{"user_id":"8", "status":"asdas", "tags":"1asd", "description":"MT11-72", "nickname":"asdasd"}}
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
{"get_general":{"user_id":"1"}}
```

**_Answer:_**
```c
{"get_general":{"user_id":"8", "status":"asdas", "tags":"1asd", "description":"MT11-72", "nickname":"asdasd"}}
```

Порядок работы:

Отдает все глобальные данные пользователя по id по аналогии с персональными.

## 8. Address data

### `Write address`

**_Response:_**
```c
{"write_address":{"user_id":"1", "building":"2", "housing":"3", "street":"Bolshaya Voskresenskaya","city":"Krasnogorsk","district":"Krasnogorskiy","index":"143430", "country":"Russia"}}
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
{"get_address":{"user_id":"1"}}
```

**_Answer:_**
```c
{"get_address":{"user_id":"1", "building":"1", "housing":"1", "street":"Bolshaya Voskresenskaya","city":"Krasnogorsk","district":"Krasnogorskiy","index":"143430", "country":"Russia"}}
```

Порядок работы:

Отдает адресс пользователю, который его же и вызвал.

## 9. MeetUp

### `Get MeetUp STATUS : complited`

**_Response:_**
```c
{"get_meetup":[{"group_id":"61", "date":"2022-01-26"}]}
```

**_Answer:_**
```c
{"get_meetup":[{"time_begin":"00:00","time_end":"00:30"},{"time_begin":"20:15","time_end":"23:30"}]}
```

Порядок работы:

Главная фича проекта. По id группы и дате отдает все возможные свободные одновременно для всех промежутки времени. 
    