// pkr2.c by konn
inherit ROOM;

void create()
{
        set("short","第一武道館");
        set("long", @LONG
牆上刻有幾個小字, 你上前仔細一看, 那似乎是克敵是勝的妙法, 只見上面
寫著「以靜制動, 以慢制快」, 這看來好像是太極拳的精義呀, 你仔細的沉
思了一下, 這句話倒也滿有道理的。這裡除了這面牆上的小字外, 場地的正
前方也掛了一幅張三豐的畫像, 看來張老師父曾以這裡作為修行的地方啊。



LONG);
        set("exits", ([ /* sizeof == 3 */
            "east"  : __DIR__"pkr3",
            "west"  : __DIR__"pkr1",
            "south" : __DIR__"pkr5",
      ]));
set("no_scale",1);
        set("no_transmit", 1);
        set("light_up", 1);
        setup();
//	enable_commands();
}
//玩家反應訊息會有問題，先關閉等找到問題後再開放吧！
/*
void receive_message(string msgclass, string msg)
{

    tell_room("/open/gblade/room/pkroom/lookpkroom",msg);
}
*/
