inherit NPC;
#include <ansi.h>

void create()
{
	set_name("貂蟬",({"diao chan","chan"}));
	set("long",@LONG
乾坤八卦塔的守護者聖女。
LONG);
	set("title",HIW"守塔者"NOR);
	set("combat_exp",100);
	setup();
}

void die()
{
object *user,me;
int i,n,sgin,skee,ssen,sforce;
	user=users();
	n = sizeof(user);
	me = this_object()->query_temp("last_damage_from");

	if ( !me ) return ::die();

	if ( me->query("id") != "iv bu" || me->query("id") != "wild man" )
	{
		message_vision(HIR"\n\n\n$N受到強大的衝擊！\n\n\n"NOR,me);
		me->set("gin",1);
		me->set("kee",1);
		me->set("sen",1);
		me->set("force",1);
		COMBAT_D->report_status(me,1);
		::die();
	}

		tell_object(users(),HIR"

	乾坤八卦塔的守護聖女被 "+me->query("name")+" 殺死了．．．整個大陸開始動搖起來！

\n"NOR);

		for(i=0;i<n;i++)
		{
			sgin=user[i]->query("gin");
			skee=user[i]->query("kee");
			ssen=user[i]->query("sen");
			sforce=user[i]->query("force");

			if ( !wizardp(user[i] ) && living(user[i]) )
			{
			tell_object(user[i],HIR"你受到了不少損傷...\n"NOR);
			user[i]->add("gin",-sgin/2);
			user[i]->add("kee",-skee/2);
			user[i]->add("sen",-ssen/2);
			user[i]->add("force",-sforce/2);
			COMBAT_D->report_status(user[i],1);
			}
		}
::die();
}
