inherit ROOM;
void create()
{
set("short", "聖域試煉之間起點");
set("long", @LONG
	經由葉秀殺的忍法幻術，你似乎來到了一種不知名的地方，
	四周的房間幾乎都是石頭打造的，建築風格也跟所熟識的中國式建築不一樣。
	難不成你已經不在中國裡面了？不會吧？
	根據葉秀殺所說，這裡應該是所謂的聖域入口，也是試煉的起點。
	前方有一個似曾相識的花園，似乎在殺手總壇的花園曾經見過。
	或許應該進去吧。。。。。

LONG );
set("exits", ([ /* sizeof() == 2 */
  "enter": __DIR__"flowrm2.c",
]));

set("no_transmit",2);
set("no_auc",1);	//代表這裡是聖域之間，必須限制auc
set("valid_startroom", 1);
setup();
}

int valid_leave(object me, string dir)
{//不通過8次試煉出不去
  me->set_temp("killrun",1);
  return 1;
}
