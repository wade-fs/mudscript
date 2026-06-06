//小師妹
#include <command.h>
 
inherit NPC;
string ask_where()
{
    object who=this_player();
    if(who->query_temp("go_kill",1) )
    {
    who->delete_temp("go_kill");
    who->set_temp("will_kill",1);
    return("她現在隱藏身份躲在聖火教之內..不過是在那一個支門我就不便說明了...\n
    她身上很喜歡帶著一支玉鐕!!\n");
    }
}

void create()
{
    set_name("小師妹",({"sister"}));
    set("title", "秦憶詩的");
    set("gender", "女性");
    set("age",23);
    set("attitude","friendly");
    set("long",@LONG

        她是玉女劍派的弟子, 當初因為其師姐陸綺芙的密謀奪書之事, 
        與另一位師姐秦憶詩遠奔西域躲避.........

LONG);
 
    set("combat_exp",122000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",500);
    set("kee",500);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",40);
    set_skill("move",40);
    set_skill("parry",40);
    set_skill("sword",40);
    set_skill("henma-steps",40);
    set_skill("girlsword",40);
    set_skill("holy-force",40);
    map_skill("move","henma-steps");
    map_skill("force", "fireforce");
    map_skill("sword", "girlsword");
    map_skill("dodge", "henma-steps");
    map_skill("parry", "girlsword");
    set("chat_chance",30);
    set("chat_msg", ({
        "武林萬物～皆為生而輪迴～!!\n\n"
        "百家兵器～獨本劍得精髓～!!\n\n",
    }) );
    set("inquiry",([
    "玉女派":"玉女派是中原的一個小門派, 可是劍法乃是高人所創!!\n",
    "劍譜":"劍譜我不知道藏在那裡!!不過掌門佩劍[紅炘劍]我知道是放在師姐的房間裡喔!!\n",
    "陸綺芙":"哼!!那個陰險的小人, 害我們有門回不得!!我知道她現在也躲起來了..\n",
    "躲起來":(: ask_where :),
 ]));
    setup();
}


