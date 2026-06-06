inherit ROOM;
#include <ansi.h>
string screen();
void create ()
{
set("short", HIW"試煉之塔--領獎區"NOR);
set("long",@LONG

一部極大的主電腦正在此處運轉著，它就是掌管著『試煉之塔』的
主電腦，你必須載入(check)晶片，才可以兌換獎品。

一個電腦銀幕(computer screen)就在你眼前。
LONG);
set("exits", ([
"west" : __DIR__"ticket",
]));
set("no_die_room",1);
set("item_desc",([
"computer screen":(:screen:),
"screen":(:screen:),
"銀幕":(:screen:),
"電腦銀幕":(:screen:),
]));
setup();
}

void init()
{
add_action("do_check_card","check");
}

string screen()
{
object me=this_player();
tell_object(me,"
"HIB"========================================================================

	"HIW"使用者："+me->query("name")+"

	目前挑戰樓層："+me->query("quest/start_game")+"

	晶片記錄："+present("fight_card",me)->query("name")+"

"HIG"『"HIR"試煉塔"HIG"』"HIW"獎品列表：

LV 10～       LV 20～       LV 30～       LV 40～       LV 50～

"HIY"黃金一兩      尚待討論      尚待討論      尚待討論      尚待討論

"HIW"LV 60～       LV 70～       LV 80～       LV 90～       LV 100～

"HIY"尚待討論      尚待討論      尚待討論      尚待討論      "HIG"成長型武器一把
                                                        感謝巫師:小渡(wataru)製作。
"HIC"P.S.  LV100以上另外有設定可以挑戰地下城

"HIY"      獎品：屬性丸
"HIR"(不是我小氣，只是目前試驗階段，不可能給什麼東西，而且我也沒收門票錢-.-)

                                       試煉塔塔主Firedancer@F.S.
"HIB"========================================================================
"NOR);
return "\n";
}


int do_check_card(string arg)
{
object me=this_player();
if(!arg)
return 0;
if(arg!="card")
{
tell_object(me,HIW"系統：錯誤，檢查物件不適用於試煉之塔。\n"NOR);
return 1;
}
	if(!present("fight_card",me))
	{
	tell_object(me,HIW"系統：錯誤，使用者無攜帶晶片。\n"NOR);
	return 1;
	}
	if(!me->query("quest/start_game"))
	{
	tell_object(me,HIW"系統：錯誤，"+present("fight_card",me)->query("name")+"檔案與"+me->query("name")+"不符合。\n"NOR);
	return 1;
	}
	if(!me->query_temp("apply_newdata"))
	{
	tell_object(me,HIW"系統：錯誤，"+present("fight_card",me)->query("name")+"資料並無更新，不能載入。\n"NOR);
	return 1;
	}
else
{
int i,j;
j=me->query("quest/start_game");
j=j-1;
i=j/10;
	switch(i)
	{
	case 0: tell_object(me,HIW"系統：此等級無獎品可拿。\n"NOR);
		me->delete_temp("apply_newdata");
		break;
	case 1: if(me->query("quest/start_game_prize")==1)
		{
		tell_object(me,HIW"系統："+new(__DIR__"prize01")->query("name")+"已經領取過，請勿重複領取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系統："+present("fight_card",me)->query("name")+"資料載入完畢。\n"NOR);
		me->delete_temp("apply_newdata");
		new("obj/money/gold")->move(me);
		message_vision(HIW"系統：恭喜"+me->query("name")+"獲得"+new("/obj/money/gold")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",1);
		return 1;
		}
		break;
	case 2:if(me->query("quest/start_game_prize")==2)
		{
		tell_object(me,HIW"系統："+new(__DIR__"prize02")->query("name")+"已經領取過，請勿重複領取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系統："+present("fight_card",me)->query("name")+"資料載入完畢。\n"NOR);
		me->delete_temp("apply_newdata");
		new(__DIR__"prize02")->move(me);
		message_vision(HIW"系統：恭喜"+me->query("name")+"獲得"+new(__DIR__"prize02")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",2);
		return 1;
		}
		break;
	case 3:if(me->query("quest/start_game_prize")==3)
		{
		tell_object(me,HIW"系統："+new(__DIR__"prize03")->query("name")+"已經領取過，請勿重複領取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系統："+present("fight_card",me)->query("name")+"資料載入完畢。\n"NOR);
		me->delete_temp("apply_newdata");
		new(__DIR__"prize03")->move(me);
		message_vision(HIW"系統：恭喜"+me->query("name")+"獲得"+new(__DIR__"prize03")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",3);
		return 1;
		}
		break;
	case 4:if(me->query("quest/start_game_prize")==4)
		{
		tell_object(me,HIW"系統："+new(__DIR__"prize04")->query("name")+"已經領取過，請勿重複領取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系統："+present("fight_card",me)->query("name")+"資料載入完畢。\n"NOR);
		me->delete_temp("apply_newdata");
		new(__DIR__"prize04")->move(me);
		message_vision(HIW"系統：恭喜"+me->query("name")+"獲得"+new(__DIR__"prize04")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",4);
		return 1;
		}
		break;
	default:tell_object(me,HIW"系統：你的晶片出了問題，請Firedancer幫你檢查吧。\n"NOR);
		me->delete_temp("apply_newdata");
		break;
	}
return 1;
}
}
