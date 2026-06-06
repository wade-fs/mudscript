// Room: /open/tendo/room/door.c

inherit ROOM;
void create()
{
        set("short", "聖龍口");
        set("long", @LONG
來到此地你發現這兒的景物與崑崙山上的聖龍口沒有兩樣，但眼
前卻出現了一座道觀。道觀似乎是漂浮在空中一般，有座橋從道觀連
接出來，但距離你還有段距離想跳上去似乎是不可能的，但是你的好
奇心還是驅使你去試試......
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "out":"/open/main/room/M13",
]));
  set("outdoors",1);
        setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_jumpup","jump");
}

int do_jumpup(string str)
{
        object who;
        who = this_player();
        if(who->query("class") != "taoist"
        || !who->query("class") );
        tell_object(who,"道觀內傳出一陣宏亮的聲音:非本派弟子,請勿入內");
        who->move("/open/center/room/inn");
        if(str!="up"){return 0;}
        tell_object(who,"你奮力一跳，腳底踏上了橋的邊緣。\n");
        who->move("/open/tendo/room/l1.1");
        tell_room(this_object(),"你看到"+who->query("name")+"奮力一跳，身形往"+
                                "上竄升，等你抬頭看時他卻已經不見了。\n");
        if(who->query("class") != "taoist"
        || !who->query("class") );
        who->move("/open/center/room/inn");
        return 1;
}
int do_search()
{
object me;
 me = this_player();
 tell_object(me,"前方好像有一塊凸地,你應該可以跳上去(jump up)。\n");
 return 1;
}
