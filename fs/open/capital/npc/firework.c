#include <ansi.h>

inherit NPC;

string	*word=({ "囍", "百年好合", "永結同心", "新婚致慶", "永浴愛河",
		 "琴瑟合鳴", "早生貴子", "雙喜臨門", "白頭偕老", "比翼雙飛",
	      });
void create()
{
	set_name("炮隊",({"firework"}));
	set("long", "這是炮隊，趕在花轎俊馬的前頭放鞭炮，"
		    "一面驅邪一面帶來喜氣。\n");
	set("age",24);
	set("gender","男性");
	set("no_kill",1);
	setup();
}

int start_marry()
{
  call_out("firework", 6+random(5));
  return 1;
}

int firework()
{
  remove_call_out("firework");
  message_vision(HIY"炮隊不時拿根香點燃手中的鞭炮。\n"NOR, this_object());
  CHANNEL_D->do_channel(this_object(), "mud",
	HIR"碰...天空中顯現出大大的\n\n\t"+word[random(sizeof(word))]+"\n\n"NOR,
	users());

  call_out("firework", 8+random(10));
  return 1;
}

int stop_firework()
{
  remove_call_out("firework");
  return 1;
}
