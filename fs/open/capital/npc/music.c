#include <ansi.h>
inherit NPC;

void create()
{
	set_name("樂隊",({"music"}));
	set("long", "這是一群鑼鼓隊，人數約有五十個，"
		    "正用力的敲敲打打，好不熱鬧哩。\n");
	set("age",30);
	set("gender","男性");
	set("no_kill",1);
	setup();
}

int start_marry()
{
  call_out("music", 6+random(5));
  return 1;
}

int music()
{
  remove_call_out("music");
  message_vision(HIY + "樂隊不時敲敲打打，倒是頗為熱鬧。\n", this_object());
  call_out("music", 5+random(3));
  return 1;
}
