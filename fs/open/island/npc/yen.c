#include <ansi.h>
string ask_me(object who);
string do_mention(object who);
inherit NPC;
int j=0 ,k=1;
void create()
{
        set_name("顏子復", ({ "yen jifu","yen","jifu"}) );
        set("gender", "男性" );
        set("age",79);
        set("str",30);
        set("cps",30);
        set("cor",30);
        set("per",30);
        set("int",30);
        set("spi",30);
        set("con",30);
        set("kar",30);
        set("long",
                "他是鄭士欣的師兄 ,為了出外找尋先祖逍遙子 ,而將掌門之位
讓給了鄭士欣 ,但他的劍術造詣無人可知 ,加上多年來苦心創
出的絕世劍招 ,更是深不可測.他看起來無精打采 . \n");
        set("force",3000);
        set("max_kee",3000);
        set("sen",7000);
        set("max_sen",7000);
        set("kee",3000);
        set("max_gin",7000);
        set("gin",7000);
        set("no_kill", 1);
        set("no_fight", 1);
        set_skill("literate",90);
        set_skill("shasword",100);
        set_skill("shaforce",100);
        set_skill("sha-array",140);
        map_skill("array","sha-array");
        set_skill("sha-steps",130);
        set("max_force",3000);
        set_skill("array",120);
        set_skill("move",150);
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",90);
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        set_skill("sword",120);
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        set_skill("unarmed",200);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set("force_factor",5);
        set("chat_chance_combat",70);
        set("chat_chance",10);
 
        set("inquiry", ([
                "鄭士欣": "他是我師弟 ,最近聽說使仙劍派變的相當強盛 .\n",
                "逍遙子" : "正是先祖 ,多年前和冥殿修羅一戰後變失去了蹤影 ,仙劍
            派用盡了任何方式 ,始終無法找到他老人家",
                "比試": (: ask_me :),
                "天鼓雷音": "這是師尊遠赴魔界前所留下之物 ,無法輕易相贈 ,除非和我(比試)一場",
                "無精打采" : "師父臨走前我答應過他老人家 ..不輕易動劍 ..",
        ]) );
        
        set("combat_exp", 1200000);
        set("attitude", "heroism");
        set("title","劍俠");
        setup();
        add_money("gold",40);
        carry_object("/open/gsword/obj/woodsword")->wield();

}

string ask_me(object who)
{
        set_name("顏子復" , ({"yen jifu","jifu","yen"}));
    set("title", "仙劍派第三代弟子");
        set("max_kee",7900);
        set("eff_kee",7900);
        set("kee",7900);
        set("no_kill", 0);
        set("have_ask_me",1);
        set("family/family_name","仙劍派");
        set("dragon-sword",1);
        set("nickname", HIW + "絕代劍俠" + NOR);  
        set("long",
                "他是鄭士欣的師兄 ,為了出外找尋先祖逍遙子 ,而將掌門之位
讓給了鄭士欣 ,但他的劍術造詣無人可知 ,加上多年來苦心創
出的絕世劍招 ,更是深不可測.他看起來生氣勃勃. \n");
        set("chat_chance_combat", 75),
        set("chat_msg_combat", ({
                (: this_object(), "special_att2" :),
                (: this_object(), "special_att" :),
                (: this_object(), "special_att3" :),
                "顏子復全身散發出一股攝人的氣魄 !\n",
          
                               })); 
        kill_ob(this_player());
        if(!present("blood-river sword")){ 
        message("vision",
                HIM + " \n"              
                "顏子復慢慢的抽出了腰間後的配劍 ..一把血紅劍身的絕代好劍 .\n\n"
                ,environment(), this_object() );
        set("attitude","aggressive");
        set("bellicosity", 1000);
        set("pursuer", 1);
        set("force_factor", 12);
        set("force", 4700);
        set("max_force", 4700);
        set("combat_exp", 2500000);
        set("revealed", 1);
       message("vision","顏子復左手朝天一指 ..手上隱隱約約的飄起了一陣煙霧...\n\n"
           HIW + "在煙嵐散去後他的手中多了一把"+HIR"血河"NOR+"\n\n\n",
        environment(), this_object());
        command("unwield sword");
        carry_object("/open/island/eqs/sword1.c")->wield();
        return HIY + "神劍" + HIR + "血河" + HIY + "出鞘 ,必飲鮮血而回 ,小子受死吧 !\n" + NOR;
                                           }        
 }
int special_att()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR + "
        顏子復長嘯道 : 嘗嘗仙劍之極意 !接招了 !
        \n" + NOR ,one);
        message_vision( " 
        顏子復平舉劍喝道 :\n\n"+HIR"                      " + HIC + "仙"+HIR"--"+HIW"霞"+HIR"--"+HIC"殘"+HIR"--"+HIW"光"+HIR"--"+HIC"閃"+HIR" "NOR+"\n\n",one);
        message_vision(HIB + "
        劍氣如海浪般的飛過來 !\n" + NOR,one);
        message_vision(HIM + "
        $N全身的血管都被劍氣割破了 !\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",50+random(70));
         COMBAT_D->report_status(one);
        return 1;
}
int special_att2()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR + "
        顏子復低吟道 : 仙劍之極招 !!
        \n" + NOR ,one);
        message_vision( "
        顏子復斜舉劍喝道 :\n\n"+HIR"                         ***"+HIW"白"+HIR"**"+HIW"龍"+HIR"**"+HIW"飛"+HIR"**"+HIW"翔"+HIR"**"+HIW"閃"+HIR"*** "NOR+"\n",one);
        message_vision(HIR + "
        你只看到眼前一片紅白交錯之光 !\n" + NOR,one);
        message_vision(RED + "
        $N全身上下佈滿著滿是像被凶獸啃掉了的大小不等的傷口 !\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",60+random(70));
         COMBAT_D->report_status(one);
        return 1;
}
int special_att3()
{
        object *me,one;
        int i;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        message_vision( HIB + "
        顏子復怒吼道 : 仙劍之禁斷劍意 !接招了 !
        \n\n" + NOR,one);
        message_vision(HIW + "
        顏子復迅速的往你一刺 !只見一到白光從劍中閃出 !\n\n\n\n"
        "你看不清楚眼前到底出現了甚麼東西 !\n" + NOR
        ,one);
        message_vision(HIR + "一股如噴泉般的血$N身上不停的噴出 !!\n\n" + NOR
                       HIY + "那個速度極快的東西仍然不停的以高速在噬咬$N的身體!!\n" + NOR
                       "一條速度極快的"+HIW" 白龍 "NOR+"在$N身邊不斷的飛舞著 !! 
瞬間便將可憐的$N緊緊的纏繞著!!
        \n" + NOR,one);
        one->receive_wound("kee",40+random(50));
        one->apply_condition("bleeding",10);
        one->start_busy(1);
        COMBAT_D->report_status(one);
        return 1;
}
 void die()                                                                 
 {
    object winner = query_temp("last_damage_from");        
    if(query("have_ask_me")==1)
 {
    new("/open/island/obj/bon.c")->move(environment(winner));   
    tell_object(winner,HIB + "\n\n顏子復的懷中滾落出一件事物\n\n\n" + NOR); 
           
  }                   
    ::die();                                                           
  }          











