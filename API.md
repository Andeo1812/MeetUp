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
{"registration":{"user_id":"56"}}
```

Порядок работы:

Клиент присылает никнейм и пароль нового пользователя, которые размещаются в базе, вовращает id нового юсера в базе.

### `Autorization`

**_Response:_**
```c
{"autorization":{"nickname":"Sasha","password":"123456asd64569898989"}}
```

**_Answer:_**
```c
{"autorization":{"user_id":"56"}}
```

Порядок работы:

Аналогично регистрации принимает ник и пароль, при соотсветвии данной комбинации отдает id.

## 2. Events

### `Add`

**_Response:_**
```c
{"add_event":[{"user_id":"56","event_name":"breakfast","event_date":"01-06-2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"}]}
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

### `Delete`

**_Response:_**
```c
{"delete_event":[{"event_id":"56"}]}
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
{"add_friend":{"user_id":"56","list_contacts":["Ibragim"]}}
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
delete_friend: {"delete_friend":{"user_id":"56","list_contacts":["Ibragim"]}}
```

**_Answer:_**
```c
{"delete_friend":"OK"}
```

Порядок работы:

По нику удаляем друга к пользователю. Операция двунаправленная.

    