int heart(object me,int time)		// me:誰 time:計時多久
{
	int a,b,q;

	q = uptime();

	if( !me->query_temp("heart_start") )
		me->set_temp("heart_start",q);
	else
		me->set_temp("heart_finish",q);

	a = me->query_temp("heart_start");
	b = me->query_temp("heart_finish");

	if( !a || !b ) return 0;

	if( b-a < time )
		return 0;
	else
	{
		me->delete_temp("heart_start");
		me->delete_temp("heart_finish");
		return 1;
	}
return 1;
}
