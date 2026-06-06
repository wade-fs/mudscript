void init()
{
	add_action("do_move",({"north","n","west","w","east","e","south","s"}));
	add_action("do_out","out");
}

int do_out()
{
object me,room;
	me = this_player();
	room = this_object();

	if ( !room->query("out") )
		return 0;

	if ( room->query("out") == 1 )
		me->move(__DIR__"b21");
	else if ( room->query("out") == 2 )
		me->move(__DIR__"e01");
return 1;
}

int do_move()
{
object me,room;
int i;
	me = this_player();
	room = this_object();

	if ( room->query("right_way") )
		i = random(9)+1;
	else
		i = random(8)+1;

	message_vision("$N往深處移動。\n",me);
	me->move(__DIR__"d0"+i);
return 1;
}
