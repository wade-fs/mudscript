#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_ask();
void create()
{
        set_name("說法大長老",({"elder"}));
        set("title","冥蠱魔教長老");
        set("gender","男性");
        set("class","poisoner");
        set("combat_exp",73632);
        set("attitude","heroism");
        set("age",60);
        set("str", 40);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 45);
        set("force",650);
        set("max_force",650);
        set_skill("dodge", 70);
        set_skill("parry",60);
        set_skill("coldpoison",60);
        set_skill("poison",100);
        set_skill("unarmed",40);
        set_skill("whip",60);
        set_skill("nine-steps",30);
        set_skill("ming-snake",40);
        map_skill("dodge","nine-steps");
        map_skill("poison","coldpoison");
        map_skill("whip","ming-snake");
	set("chat_chance_combat",60);
	set("chat_msg_combat",({
	(: perform_action,"poison.five" :),
	(: perform_action,"poison.dark" :),
	}));
        set("force_factor", 5);
        set("inquiry",([
        "入教":   (: do_ask :),
        ]));

        setup();
        carry_object(POISON_OBJ"green_whip")->wield();
	carry_object("/obj/poison/five_poison")->add_amount(30);
	carry_object("/obj/poison/dark_poison")->add_amount(30);
  carry_object("/obj/poison/scorpion_poison")->set_amount(15);

}

void init()
{
        add_action("do_say","say");
}
string do_ask()
{
        object me=this_player();
        command("hmm");
        if(me->query("poison_low"))
                return "你不是已經加入冥蠱魔教了。";
        if(!me->query("class"))
                return "你還是先選擇職業吧。";
        me->set_temp("elder1_temp",1);
        return "你是不是想來加入我教的? ";
}
int do_say(string str)
{
  object me = this_player();
  string myclass=me->query("family/family_name");

  if(me->query_temp("elder1_temp")){
        if(str == "yes" || str == "是")
          {
            me->delete_temp("elder1_temp");
            me->set_temp("poison_pass1",1);
            message_vision(sprintf(HIC + "$N說道﹕"+str+"\n" + NOR),me);
            command("smile");
        if(myclass == "冥蠱魔教"){
                command("say 雖然你直到現在才來申請正式加入，但看你如此忠誠。");
                command("say 我就同意你正式成為我教一員，將來好好學習。");
                return 1;
                }
        if(myclass || (me->query("class")!="poisoner")){
                command("say 雖然你已加入別派，然你有意入我派。");
                command("say 切記將來雖委身他派，亦要信奉教令。");
                command("say 你可以去徵求其他長老同意了。");
                return 1;
                }
            command("say 看你不辭辛苦遠道而來的精神上，我就同意你。");
            command("say 將來好好學習吧");
            return 1;
          }
        else
           {
            message_vision(sprintf(HIC + "$N說道﹕"+str+"\n" + NOR),me);
            command("say 哼！既然沒誠意加入就別來。");
            me->delete_temp("elder1_temp");
            return 1;
           }
        return 0;
}
}
