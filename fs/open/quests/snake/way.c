int valid_leave(object me,string dir)
{
	if( present("snake-soldier",environment(me)) )
	{
		message_vision("守衛大喝：兄弟們～別讓"+me->name(1)+"跑了～\n",me);
		return notify_fail("你的退路已經被擋住了。\n");
	}
return 1;
}
