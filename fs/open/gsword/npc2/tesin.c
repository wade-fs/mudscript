#include <ansi.h>
inherit NPC;
string ask_yao();
string ask_array();
string ask_sunsword();
string ask_bloodking();
string ask_god();
string ask_array2();
string ask_ball();
void create()
{
set_name(HIW + "龍鐵心" + NOR,({"tesin long","tesin"}));
set("long","傳說中的大劍師..開天三靈器的創作人.生平事跡不為常人所知..生活方式亦出人意料.\n");
        set("gender","男性");
        set("class","swordsman");
            set("family/family_name","仙劍派");
            set("combat_exp",14000000);
            set("attitude","heroism");
            set("dragon-sword",1);
            set("bellicosity", 5000);
        set("age",120);
        set("title",HIY + "大劍師" + NOR);
            set("str", 50);
            set("cor", 50);
            set("cps", 50);
            set("con", 50);
            set("int", 50);
            set("max_gin", 4000);
            set("gin",4000);
            set("max_kee", 30000);
            set("kee",30000);
            set("s_kee",1000);
            set("max_s_kee",1000);
            set("force",250000);
            set("max_force",2500000);
            set_skill("literate",120);
            set_skill("magic",100);
            set_skill("spells",100);
            set_skill("sun_fire_sword",100);
            set_skill("shaforce",150);
            set_skill("sha-steps",100);
            set_skill("sha-array",100); 
        set_skill("array",100);
        set_skill("move",120);
        set_skill("force",300);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("sword",120);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","sun_fire_sword");
        set("force_factor",50);
                set("inquiry",([
        "逍遙子"   :  (: ask_yao :),
        "天門奇陣"   :  (: ask_array :),
        "仙劍連陽" : (: ask_sunsword :),
        "血魔" : (: ask_bloodking :),
        "神聖俠": (: ask_god :),
        "開天三才陣" : (:ask_array2:),
        "連陽劍晶珠" : (:ask_ball:),

        ]));
        setup();
        add_money("gold", 10);
        set("get_sha_sp", 1);
        set("chat_chance_combat",90);
        set("chat_msg_combat",({
        (: perform_action,"sword.sha_kee" :)
        }));
        carry_object("/open/gsword/obj/dragon-sword")->wield();
        create_family("仙劍派",2,"不傳弟子");
}

string ask_yao()
{
command("say 你說好友逍遙子是嗎?他已經消失很久了.在神聖俠大戰血魔後..就沒他的行蹤了");
 return("不過..據說有人在搜尋他的蹤跡.據說為了搜尋逍遙子的下落..他已經消失武林一陣子了 !\n");
}
string ask_array()
{
 return("天門奇陣乃是逍遙子從大破魔師-於蘭天武-學來專門克制血魔的陣法. !\n");
}

string ask_sunsword()
{

command("say 仙劍連陽..具逍遙子說..是破魔師於蘭天武給他的破魔聖物.劍上並鑲上破魔晶珠..");
 return("不曉得破魔師是如何得到他的...!\n");

}

string ask_bloodking()
{

 return("應該已經被封印在天門奇陣中了..至於天門奇陣在哪..可能得去問問風青雲了 !.\n");

}

string ask_array2()
{

command("say 根據破魔師於蘭天武所說天門奇陣中為了壓抑血魔魔力..因此得陣中加陣... !");
command("say 開天三才陣乃集神聖俠三人靈氣..配上開天三靈器之靈力所形成之次空間 !");
 return("目前武林中的開天三靈器..則因為大部分靈氣已被陣法吸收..因此威力已不及當初的貳分之一 !\n");

}
string ask_god()
{

command("say 當時..逍遙子號增劍聖..他集合了當時與他齊名的歐陽禮及司馬破軍參與封魔大戰!");
 return("之後..就是我用仙劍連陽幫他們分別鑄造了專用武器...接下來的..就要去問別人了!\n");

}
string ask_ball()
{
 if(!this_player()->query_temp("swordtime"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  if (this_player()->query("class")=="swordsman")
    {
    this_player()->set_temp("swordquest/findball",1);
    return ("連陽劍晶珠為連陽劍靈力之來源，然則因封印血魔所需，因此在三靈器流傳狂想世界大陸時，晶珠早已不在靈器中，故三靈器並無法發揮應有之威力。\n然則似乎有聽金風細雨樓樓主說過，晶珠似乎在他手中!!");
   }
else return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
 }
}
