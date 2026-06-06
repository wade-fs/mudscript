// Room: /u/s/sueplan/newplan/area/qroom1
inherit ROOM;

void create ()
{
  set ("short", "§八卦陣§");
  set ("long", @LONG
                      乾 （天）
                 兌     ________     巽
                  ╱   ________    ╲
          （澤）╱ ╱   ________   ╲   （風）
              ╱ ╱ ╱            ╲ ╲ ╲
               ╱                   ╲ ╲
                ╱                    ╲

       離  │││                      │││  坎
           │  │                        │
     （火）│││                      │││（水）

                ╲                    ╱
               ╲                      ╱
              ╲   ╲  ___  ___  ╱    ╱
            艮  ╲ ╲   ___  ___   ╱     震
                  ╲    ___  ___    ╱
              （山）                （雷）
                        屆地）

八卦陣──從古代中國之易經中所演變而來；乾、巽、坎、艮、坤、震、
離、兌，即為其八個卦象；你一踏入此陣之後，內心起了一個疑問？教主
為何會設八卦陣於此？此時強烈的好奇心驅使著你，讓你不由自主的想闖
一闖此陣，此八卦鎮內包含了各項危機，請愛惜生命。
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/man.c" : 1,
]));
  set("evil", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"f17.c",
]));
  set("no_auc", 1);

  setup();
}
void init()
{
add_action("do_search","search");
add_action("do_go","go");
}
int do_go(string str)
{
  object me;
  me=this_player();
  if(str=="陣內")
  {
    if(me->query_temp("six_ask")==10)
    {
    write("你深深的吸了一口氣, 進入了八卦陣內!!\n");
    me->move(__DIR__"q2.c");
    return 1;
    }
  else
  {
  write("你還不知道什麼是八卦陣吧??\n");
  }
  }
}
int do_search()
{
  object me=this_player();
  if( me->query("family/family_name") =="儒門")
  {
  write("你發現有條路可以進入此陣(go 陣內)。\n");
  }
  else
  {
  write("你找不出個所以然出來\n");
  }
return 1;
}
