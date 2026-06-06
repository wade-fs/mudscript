//這種等級的mob不應該帶著iceger所以拿掉by cyw 91/04/05
inherit NPC;
void create()
{
        set_name("韋一笑",({"green-bat king","king"}));
        set("gender","男性");
        set("age",35);
        set("class","poisoner");
        set("str",30);
        set("long", "擁有一張令人不敢恭維的臉 ,和一雙精明的小眼睛 ,他正在房間中跺
著步子 ,好像在等什麼人的樣子 ...\n");
        set("bellicosity", 1000);
set("max_kee",2000);
        set("kee",2000);
        set("max_force",3000);
           set("force",3000);
        set("force_factor",10);
        set("combat_exp",800000);
        set_skill("unarmed",100);
        set_skill("parry",80);
        set_skill("poison",100);
        set_skill("dodge",100);
        set_skill("lungshan",100);
        set_skill("henma-steps",100);
        set_skill("haoforce",80);
        set_skill("coldpoison",80);
        map_skill("unarmed","lungshan");
        map_skill("dodge","henma-steps");
        map_skill("move","henma-steps");
        map_skill("parry","lungshan");
        map_skill("force","haoforce");
        set("inquiry",([
           "赤火令" : "那是教主的令牌 ,一般人拿不到的。 ",
           "化骨綿掌"   : "那是我發明的絕招 ,只傳給教主的使者。",
        ]));
        setup();
        create_family("冥蠱魔教",3,"護教法王");
 //       carry_object("/open/ping/obj/iceger")->wield();
        add_money("gold",10);
carry_object("/obj/poison/rose_poison")->set_amount(20);
carry_object("/obj/poison/five_poison")->set_amount(20);
carry_object("/obj/poison/dark_poison")->set_amount(20);
carry_object("/obj/poison/faint_poison")->set_amount(20);


}


int accept_object(object me,object ob)
{
  if(ob->query("id")=="firer")
   {
        if(me->query("mark/melt-bone"))
      {
       command("say 化骨綿掌好用吧 !");
       return 1;
      }
      if(me->query("class")!="poisoner")
    {
        command("kill "+me->query("id"));
        command("say 你不是魔教徒 ,怎麼拿的到赤火令 ?受死吧!");
    }
      if(!me->query_temp("playboy"))
    {
              command("shake "+me->query("id"));
              command("say 誰讓你進來的 ?");
    }

   else {
        command("smile "+me->query("id"));
        if(me->query("gender")=="男性")
        command("say 小師弟 ,恭喜你喔 !");
        if(me->query("gender")=="女性")
        command("say 小師妹 ,真是女中豪傑 !");
        me->set("mark/melt-bone",1);
        command("say 拿的到赤火令 ,表示你有資格得到我神教不傳絕學了 !");
        message_vision("韋一笑將雙掌貼上你的背門 ,一股陰毒內力透體而來,
往你七筋八脈流去 !\n",me);
        tell_object(me,"你感到一陣酥麻 ,感到說不出的受用 !\n");
        }
  return 1;
    }
}

