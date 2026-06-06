#include <ansi.h>
inherit F_VENDOR;

string magic1();
string magic2();
string do_tendo();
string do_master();
string do_hawk();
string do_area();

void create()
{
	set_name("龍清和",({"chinho"}));
	set("long","陸清風的師兄,因全心致力於武學之上,故將掌門之位讓給他師弟"
                   "!!\n");
        set("gender","男性");
        set("class","taoist");
        set("combat_exp",1500000);
        set("attitude","heroism");
		set("age",91);
        set("title","天道派護法長老");
        set("str", 25);
        set("cor", 29);
        set("cps", 28);
        set("per", 24);
        set("spi", 25);
        set("int", 26);
        set("force", 3000);
        set("max_force", 3000);
        set("max_mana",2000);
        set("mana",2000);
        set("max_atman",2000);
        set("atman",2000);
        set_skill("literate", 70);
	set_skill("cure",60);
	set_skill("taoism", 100);
	map_skill("cure", "taoism");
	set_skill("magic",80);
	set_skill("gmagic",90);
	map_skill("magic","gmagic");
	set_skill("spells",80);
        set_skill("necromancy",90);
	map_skill("spells","necromancy");
        set_skill("force",50);
        set_skill("gforce",80);
        map_skill("force","gforce");
        set_skill("dodge",40);
        set_skill("g-steps", 70);
        map_skill("dodge","g-steps");
        set_skill("parry",60);
        set_skill("whip",70);
        set_skill("gwhip",70);
        map_skill("whip","gwhip");
        map_skill("parry","gwhip");
        set("force_factor", 30);
		set("inquiry",([
        "天道派" : (:do_tendo:),
        "陸皓雲" : (:do_master:),
        "靈鷹" : (:do_hawk:),
        "崑崙仙境" : (:do_area:),
          ]));
        setup();
        carry_object("/open/tendo/obj/whisk")->wield();
        carry_object("/open/tendo/obj/hat")->wear();
        carry_object("/open/tendo/obj/shoe")->wear();
        carry_object("/open/tendo/obj/robe")->wear();
}
string do_tendo()
{
  object who=this_player();
  if(who->query("class")!="taoist")
        return "此事為天道派本門機密，貧道豈能告知外人。";
  who->add("quest/ask_tendo_hawk",1);
  return HIY"唉！！！\n            其實當年眾妖大鬧人間，先師陸皓雲親率本門道魂三使者大戰群魔，\n            不料卻在戰魂坡慘遭群妖圍攻，先師以靈鷹配合天道秘術形成一道強\n            大的陣法困住眾妖危害人間，之後雖然武林中各大派趕來救援不及，\n            導致先師身受重傷，如今生死不明。"NOR;

}

string do_master()
{
  object who=this_player();
  if(who->query("class")!="taoist")
        return "沒聽說過。";
  who->add("quest/ask_tendo_hawk",1);
  return HIY"其實當年大戰之後先師因傷勢嚴重，便將掌門之位傳於清風師弟，便\n            攜同靈鷹前往崑崙仙境閉關修練道法，日前闡悟道法，長辭人世。"NOR;
}

string do_hawk()
{
  object who=this_player();
  if(who->query("class")!="taoist")
        return "聽說過。";
  who->add("quest/ask_tendo_hawk",1);
  return HIY"嗯！靈鷹乃當年先師遨遊崑崙山時無意中在崑崙仙境發現此吸收靈氣\n            而生長成的靈鷹，由於此鷹極通靈性，加上先師助其靈氣灌頂，靈鷹\n            便長守崑崙山，背負起守護天道派的重責大任。"NOR;
}

string do_area()
{
  object who=this_player();
  if(who->query("class")!="taoist")
        return "陸清和搖搖頭，說道﹕沒聽說過。";
  who->add("quest/ask_tendo_hawk",1);
  return HIY"崑崙仙境為先師仙逝之處，亦為我天道禁地，詳情你還是去詢問清風師弟吧！"NOR;
}

