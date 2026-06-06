// Room: /open/poison/room/eqroom.c
inherit ROOM;

void create ()
{
  set ("short", "器物間");
  set ("long", @LONG
這裡是眾魔教徒休息的地方 ,也是先進的教徒獎掖後進的所在 ,代
表了魔教教徒間那種高度的友愛 ,另外 ,這裡亦是魔教徒交換各種神兵
利器的地方 ,所以各位師兄師姊們 ,有好東西別只顧埋了 ,留給小師弟
師妹吧 !這裡有個大書架(shelf)
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"shelf" : "一個看起來沉重而老舊的書架 ,上面佈滿了灰塵 ,
但是在書架的兩側 ,卻不自然的一塵不染 ,好像有人轉
過架上的書都很舊了 ,不過翻動的痕跡倒是不少 ,令人
詫異的是 ,都已經有圖書室了 ,何必費盡心思搬個書架
到這來。
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room1.c",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
     set("no_clean_up",1);

  setup();
}
void init()
{
        add_action("do_turn","turn");
}

int do_turn(string str)
{
        object who;
        who = this_player();

        if(!str || str != "shelf")
                return notify_fail("你想轉動什麼？\n");
        else{
             tell_object(who,"\n你將書架轉開 ,進入了後邊的秘門。\n\n");
             who->move("/open/ping/room/road3.c");
             tell_room(this_object(),who->query("name")+"把書架轉開 ,進入秘道中。\n");
            }
        return 1;
}
int valid_leave(object me, string dir)
{
if (dir == "down" && me ->query("class") != "poisoner")
  if ( !wizardp (me) )
     return notify_fail("喂 ,進去幹麻 ?想被毒啊。\n");
     return :: valid_leave(me, dir);
}

