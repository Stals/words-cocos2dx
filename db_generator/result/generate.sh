rm words.sqlite
db_generator.exe

#нужно просто конверитровать в ноду как это делает menuItem чтобы определить тач.
#http://stackoverflow.com/questions/11141112/detect-touch-cocos2d-x
# может имеет смысл наслодоваться от меню ? и передавать в кнопку чтобы она вызывала метод который будет просто говорить id свой? 
# мне даже это не нужно - мне нужно просто самому определить id letterа - и дать возможность его сделать visible false и добавить его в слово игрока.

# ну например я говорю в word - вызови вот этот метод 
# а word говорит буквам вызвать его метод который вызовет тот метод. 
# тоесть в слове должен лежать callback в который я заодно передам id по хорошему.
# зная который мы скажем сделать visible false - 
# а лучше сделать fade или затемнить например, чтобы все еще было видно слово.

# можно id внутри удалить наверно, хз нужно ли оно там вообще

# нужна наверно возможность узнать глобальные координаты чтобы создать букву где нужно - потом оттуда ей сделать полет до другого места

# когда я кликаю - буква уже добавилась у игрока. - но она visible(false)
# когда фейковая буква до туда долетает - мы просто её удаляем и делаем visible(true). 

# при определении точки еще нужно скорее всего учитывать padding - типо width + padding*id
# можно опятьже просто глянуть на код CCMenu

# Letter - просто CCMenuItem 
# Word - CCMenu
	# тут просто добавляем как и сейчас - только часть методов за нас уже реализована.
	# наверно можно даже touchBegan не переопределять. Разница только в том что я ... callback вызываю с параметром и все?

	# 	на самом деле странно то что я должен же учитывать ширину спрайто в adjust - но это не происзодит. 
	# так что мне нужно скорее всего реально наследоваться, но посмотрим...