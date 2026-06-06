// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
        set("short","單將軍廟");
  set ("long", @LONG
這是一座供奉單信的廟宇 . 單信是第一任守衛隊隊頭 , 在
他任職的十年內 , 倭寇六度來犯 , 單信一次次英勇的帶領著隊
員們擊退敵人 , 不幸在最後一次征戰中重傷身亡 . 居民們感謝
他的恩德 , 在此立廟 , 並尊稱他為單將軍 . 這裡平日香火都十
分鼎盛 .

LONG);

        set("no_fight",1);
        set("no_magic",1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
        "east" : "/open/port/room/r2-2",
]));

  setup();
}
