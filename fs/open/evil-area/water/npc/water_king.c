inherit NPC;
#include <ansi.h>

void create()
{
	set_name("水柔纏",({"water king","king"}));
	set("age",15012);
	set("gender","女性");
	set("long","
她就是邪靈界五大邪將，掌管水行區域的邪將--水柔纏，一
副清晰可人的臉孔，似水柔纏的氣息，感覺上彷彿一位弱不
經風的女子，誰會將她與殘冷無道的邪靈扯在一起ㄋ??....
如今，她就猶如一位斷了線的人偶，不斷的哭泣，你看她哭
的面黃飢瘦，或許\應該趕快將手上的餐\食給她吧...\n");
	set_skill("unarmed",300);
	set_skill("dodge",300);
	set_skill("force",400);
	set_skill("move",300);
	set("no_kill",1);
	setup();
}

int accept_object(object me,object obj)
{
object ob = this_object();

	if( obj->query("id") == "evil-foods" )
	{
		if( me->query_temp("evil/water/ask-mission-4") )
		{
			message_vision("$N望著$n給的"+obj->name(1)+"，漸漸的眼淚\緩緩的從眼頰滑落...\n",ob,me);
			command("sigh");
			command("say 想必夫郎一定挨餓於地獄牢內...我如何嚥的下食ㄋ...:~...\n");
			message_vision("說完，$N拿起"+ob->name(1)+"，打開窗戶便往外丟～\n",ob);
			me->set_temp("evil/water/hall",1);
		}
	}
call_out("do_dest",1,obj);
return 1;
}

int do_dest(object obj)
{
destruct(obj);
}
