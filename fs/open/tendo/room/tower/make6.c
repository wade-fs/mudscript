
inherit ROOM;

int do_climb(string str);
string show_ring();

void create()
{
    set("short", "樹壁上");
    set("long", @LONG
你正掛在樹壁之中，往下看去發現你離地面有一段距離了，往上
看去，那塊突起的樹幹也不是很遠了，在你身邊釘著一個鐵環(ring)。

LONG
        );
    set("item_desc", ([
    "ring" : (: show_ring :)
    ]) );
     set("outdoors",1);

        setup();
}

void init()
{
    reset();
    add_action("re_route_cmd","",1);
    add_action("do_climb", "climb");
}

int re_route_cmd(string str)
{
    string cmd;
    int i;
    string *invalid_cmds;
    cmd = query_verb();
    invalid_cmds = ({"enforce", "meditate", "practice", "study", "wield", 
"exercise", "learn", "scribe", "conjure", "enchant", "exert", "perform", 
"respirate","drop"});
    i = member_array(cmd, invalid_cmds);
    if (i == -1) return 0;
    else write("以你目前的處境來看，要做這件事很難。\n");
    return 1;
}

int do_climb(string str)
{
    int chance;
    if (this_player()->query_temp("looked_ring")) chance = 10;
    else chance = random(10);
    if (!str) return notify_fail("往那爬? 爬那裡?!?是要往上還下爬??\n");
    if ((str != "up") && (str != "down"))
        return notify_fail("嗯.... 這裡沒有這樣東西讓你爬.\n");
    write("你深深地吸了一口氣，看準方位，慢慢的開始爬...\n");
    if ((str == "up" ) && (chance >= 8)) {
        this_player()->move(__DIR__"make7");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"氣喘噓噓地爬了上來.\n",
        this_player());
    return 1;
    }
    else {
        if ((str == "down" ) && (chance >= 8)) {
        this_player()->move(__DIR__"make5");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"很小心地從上面爬下來.\n",
        this_player());
        return 1;
        }
        else {
            write("一不小心沒抓好.... 掉了下去... 摔得你頭昏眼花.\n");
            this_player()->receive_damage("kee", 50);
            this_player()->move(__DIR__"make5");
            tell_room(environment(this_player()),
            "你聽到一聲慘叫, "+(string)this_player()->name()+"從上面摔了"+
            "下來.\n",
            this_player());
        }
    }
    return 1;
}

string show_ring()
{
    this_player()->set_temp("looked_ring",1);
    return "一個生鏽的鐵環，約有手掌般大，上面還有一截斷掉的繩子，不知是那個倒\n"+
    "霉鬼留下來的. 你試了試鐵環... 決定還是冒個險吧. 小心點就是了.\n";
}



