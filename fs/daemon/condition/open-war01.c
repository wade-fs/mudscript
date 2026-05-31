#include <ansi.h>
int i,j,k;

int update_condition(object me,int duration)
{
mixed enemy;
int i;
	enemy = all_inventory(environment(me));

        if( duration >= 1 )
        {
		if( environment(me)->query("mark") == 9 )
		{
			if ( me->query("id") == "iv bu" )
			{
				me->move("/u/f/firedancer/log_file/logroom");
				present("log man",environment(me))->delete("open-war01");
			}
			destruct(me);
		}

		if(sizeof(enemy)!=0)
		{
			for(i=0;i<sizeof(enemy);i++)
			{
				if ( enemy[i]->query("id") != "wild man" && enemy[i]->query("id") != "iv bu" && !enemy[i]->is_corpse() && enemy[i]->is_character() )
				{
					enemy[i]->kill_ob(me);
					me->kill_ob(enemy[i]);
				}
			}
		}

		if( !me->is_fighting()  )
		{
			message_vision(HIR"$N嘶喊著：積魯啊～撲魯撒馬～！\n"NOR,me);
			me->do_command("up");
		}
        }

                if( duration < 1 )
                        return 0;
        return 1;
}
