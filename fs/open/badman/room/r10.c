// Room: /open/badman/room/r10

#include "/open/open.h"

inherit ROOM;

int blade = 5;
int sword = 5;
string look_shelf();

void create ()
{
  set ("short", "兵器庫");
  set ("long", @LONG
這裡是惡人谷的兵器庫，房間四周的架子(shelf)上放滿了各式
各樣的兵器，多的足夠讓一百名山賊傾巢而出。雖然架子上的武器
都不是什麼稀世兵器，但都還算實用，或許你可以找一樣武器來試
試看。你看到牆上貼了一張佈告(note)。

LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "note" : "要申請武器請向值班人員報告所需武器種類( report 武器 )。
",
  "shelf" : (: look_shelf :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"b6",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/wguard" : 2,
]));

  setup();
}

void init()
{
	add_action("do_report", "report");
	add_action("do_take", "take");
}

int valid_leave(object who, string dir)
{
	if( dir=="up" && present("guard", this_object()) )
		return notify_fail("守衛擋在你面前說道：這裡禁止進入。\n");
	return ::valid_leave(who, dir);
}

string look_shelf()
{
	object who = this_player();

	if( !blade && !sword )
		return "架子上已經沒有你可以用的武器了。\n";
	tell_object(who,"你看到架子上有：");
	if( blade )
		tell_object(who,chinese_number(blade)+"把鋼刀\n");
	if( sword )
		tell_object(who,"\t\t"+chinese_number(sword)+"把短劍\n");
	return "";
}

int do_report(string weapon)
{
	object who, guard;
	who = this_player();
	guard = present("guard", this_object());

	if( !guard )
	return notify_fail("根本就沒人你還報告啥啊？直接拿(take)啦！\n");
	if( !weapon || (weapon!="鋼刀" && weapon!="短劍") )
		return notify_fail("你要申請哪一種武器？\n");
	if( who->query("family/family_name")!="惡人谷" )
		return notify_fail("守衛說道：你不是惡人谷的人，少來煩我。\n");
	if( who->query_temp("get_weapon") ) {
		return notify_fail("守衛看了看你說：小子，你不是拿過了嗎？\n");
	}
	if( weapon=="鋼刀" ) {
		if( !blade )
			return notify_fail("守衛看了看架子後說道：已經沒有鋼刀了。\n");
		else {
			message_vision("守衛拿了一把鋼刀交給$N。\n", who);
			new(BAD_OBJ"steel_blade")->move(who);
			blade--;
		}
	}
	if( weapon=="短劍" ) {
		if( !sword )
			return notify_fail("守衛看了看架子後說道：已經沒有短劍了。\n");
		else {
			message_vision("守衛拿了一把短劍交給$N。\n", who);
			new(BAD_OBJ"short_sword")->move(who);
			sword--;
		}
	}
	who->set_temp("get_weapon", 1);
	return 1;
}

int do_take(string weapon)
{
	object who, guard;
	who = this_player();
	guard = present("guard", this_object());

	if( !weapon || (weapon!="鋼刀" && weapon!="短劍") )
		return notify_fail("你要拿什麼？\n");
	if( guard )
		return notify_fail("守衛對你怒喝道：你要幹什麼！看不懂牆上的佈告啊？\n");
	if( weapon=="鋼刀" ) {
		if( !blade )
			return notify_fail("鋼刀早就沒啦！還輪的到你拿？\n");
		else {
			message_vision("$N從架子上拿了一把鋼刀。\n", who);
			new(BAD_OBJ"steel_blade")->move(who);
			blade--;
		}
	}
	if( weapon=="短劍" ) {
		if( !sword )
			return notify_fail("短劍早就沒啦！還輪的到你拿？\n");
		else {
			message_vision("$N從架子上拿了一把短劍。\n", who);
			new(BAD_OBJ"short_sword")->move(who);
			sword--;
		}
	}
	return 1;
}
