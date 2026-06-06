// 段家 門人 made by onion
// add 臨書點穴之謎by bss
#include "/open/open.h"
inherit NPC;
string do_wantlook();
void create()
{
        set_name("段小詩",({"duan"}));
        set("long","段小詩是段雲的獨生女, 她就站在窗前, 襦裙嬝嬝, 蠻纖垂笑。\n");
        set("gender","女性");
        set("class","scholar");
        set("combat_exp", 4000);
        set("attitude","peaceful");
        set("age",19);
        set("chat_chance", 5);
        set("chat_msg", ({
        "段小詩道: 大師哥怎麼還沒回來啊。\n",
        "段小詩道: 好想學「一陽心法秘笈」上的絕招喔。\n",
        "段小詩道: 這本鬼畫符的到底是什麼玩意兒啊。\n",
        }));
        set("inquiry", ([
        "thief" : "京城的盜賊喔, 關我們段家什麼事啊?",
        "scar"  : "人家哪有什麼傷痕啊, 你不要胡言亂語的喔。",
        "sad_story" : "人家年紀輕, 問什麼傷心往事嘛..",
        "一陽心法秘笈"  : "這裡頭記載了一個絕招喔。",
        "鬼畫符" : "也不知道是誰擺\在我的房間的，看都看不懂，你如果(想看)的話，給你看看也無彷。",
        ]));
        set("force",100);
        set("max_force",100);
        set("force_factor", 1);
        set_skill("force",10);
        set_skill("unarmed",30);
        set_skill("sunforce",10);
        set_skill("linpo-steps",30);
        set_skill("six-fingers",20);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("unarmed","six-fingers");
        set_temp("apply/dodge",30);
        setup();
        carry_object(PING_OBJ"cloth2")->wear();
        carry_object(PING_OBJ"cape0")->wear();
        add_money("coin",100);
        create_family("段家",11,"弟子");
}
string do_wantlook()
{
    object ppl,ob;

    ppl=this_player();
    ob=this_object();

    if(ppl->query("family/family_name") != "段家")
      return "哼，我跟你很熟嗎，幹嘛要給你??";
  
    return "大師哥到底什麼時候回來啦";
}


