
inherit ROOM;

string long_desc();

void create()
{
    set("short", "茅蘆");
    set("long", (: long_desc :) );
    set("long.desc", @LONG
你來到了此地，忽然發現，茅蘆竟然是建在一棵齊腰而斷的大樹
上，在這裡你聽到了，一陣陣叮叮噹噹的聲音從屋內傳了出來，往上
看似乎可以看到一塊突出來的樹幹。樹幹上可看到不少凹洞(hole)。
LONG
        );
    set("item_desc", ([
    "hole" : @HOLE
仔細地觀察這些凹洞後，你發現這裡原來可能有一座通往上面的梯子，
試了試那些洞，你想你「可能」爬得上去....

HOLE
    ]) );
    set("exits", ([
    "east" : "/open/tendo/room/tower/make4",
]));
         set("outdoors",1);

        setup();
}

void init()
{
    add_action("do_climb","climb");
}

string long_desc()
{
    string str;
    object ob;
    str = query("long.desc");
    ob = first_inventory(__DIR__"make6");
    if (!ob) return str+"\n";
    else
    return sprintf("%s\n可憐的%s正在上面掙扎。\n",
        str,(string)ob->name());
}

int do_climb(string str)
{
    object ob;
    return notify_fail("梯子的痕跡已經很淺了, 你的直覺告訴你, 你爬不上去!!\n");
    if (!str) return notify_fail("往那爬? 爬那裡?!?試試爬牆或往上爬嘛!!\n");
    if ((str != "wall") && (str != "up"))
        return notify_fail("嗯.... 你不可能爬得上去的。\n");
    ob = first_inventory(__DIR__"make6");
    if (!ob) {
        write("你深深地吸了一口氣，看準方位，慢慢的往上爬...\n");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"深深地吸了一口氣，開始往上爬。\n",
        ({this_object(), this_player()}) );
        this_player()->move(__DIR__"make6");
        return 1;
    }
    else {
        return notify_fail(sprintf("你抬頭看去，%s正在很努力的往上爬... 不要嚇他...\n",
                                    (string)ob->name()));
    }
}



