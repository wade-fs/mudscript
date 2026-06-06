#include <ansi.h>

inherit NPC;

string long ();

string	*word = ({
	"唐僧取經",
	"疊羅漢",
	"跳火圈",
	"踩高橇",
	"高空飛人",
	"扔瓶子",
	"丟飛刀",
	"吞長劍",
	"吞火球",
	"赤足過炭火",
});

void create()
{
	set_name("雜耍團",({"misc"}));
	set("long", (: long :) );
	set("age",30);
	set("gender","男性");
	set("no_kill",1);
	setup();
}

string long()
{
  return "這是一群雜耍團，目前正演出"+word[random(sizeof(word))]+"。\n";
}

int start_marry()
{
  call_out("misc", 5+random(3));
  return 1;
}

int misc()
{
  remove_call_out("misc");
  message_vision(HIY + "雜耍團突然變換隊形，表演出\t"+word[random(sizeof(word))]+
	"\n", this_object());
  call_out("misc", 10+random(3));
  return 1;
}

int stop_misc()
{
  remove_call_out("misc");
}
