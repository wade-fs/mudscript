#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "石穴");
        set ("long", @LONG
你移開雕像之後，走進了這個洞穴，發覺裡頭一點亮光都沒有，
伸手不見五指，更不用談要查看四周的環境了，當你正自摸黑搜索時
，不知不覺中好像踢到了什麼東西，你心中不禁想著：要是能製造出
一點點光源就好了...
LONG);
        set("exits", ([
        "out"    : __DIR__"mon48",
]));
        setup();
}

void init()
{
        add_action("con_light","conjure");
        add_action("con_light","conjur");
        add_action("con_light","conju");
        add_action("con_light","conj");
        add_action("con_light","con");
        add_action("con_light","co");
}

int con_light(string arg)
{
        object me = this_player();
        object room = this_object();
        object ske = new("/open/mon/obj/skeleton");
        object fire = new("/daemon/class/taoist/gmagic/obj/lightfire");
        
        if(me->query_temp("icestorm/ice_spell")==5)
        {
        if(!arg || arg != "lightfire") return 0;
                message_vision("
$N兩指一比，造出了一枚$n飄在空中。\n
$N用$n四處照了照，竟赫然發現角落有具披著道袍的骨骸...\n\n",me, fire);
                fire->move(me);
                ske->move(environment(me));
                me->set_temp("icestorm/ice_spell",6);
                return 1;
        }
}
