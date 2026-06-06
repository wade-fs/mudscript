// wang.c by oda

#include <ansi.h>
#include "../start.h"

inherit NPC;

void create()
{
	set_name("王老板", ({ "wang" }) );
	set("gender", "男性");
	set("combat_exp",8);
	set("long", "你看到一個中年男子正站在櫃台裡高興的算錢。\n");

	setup();
}

int accept_object(object who , object item)
{
	int letter;
	letter = who->query_temp("letter");

	if( item->query("id") == "sheik's letter" ) {
		if( letter==1 || letter==3 ) {
			tell_object(who,"王老板小聲的對你說：喔！是凌雲村村長叫你送來的嗎？\n真是謝謝你，麻煩再你回去告訴(report)他我已經收到了。\n");
			if( letter==1 )
				who->set_temp("letter", 2);
			else
				who->set_temp("letter", 4);
		}
	}
	return 1;
}
