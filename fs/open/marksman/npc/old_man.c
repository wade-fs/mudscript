inherit NPC;
string do_act();
string do_aca();
string do_acb();
string do_acc();
void create()
{
        set_name("老人",({"old man","man"}));
        set("gender","男性");
        set("age",70);
        set("str",30);
        set("long","一位白髮蒼桑的老人。\n");
        set("chat_chance",10);
        set("inquiry",([
        "弓老人" : (:do_acc:),
        "李廣" : (:do_act:) ,
        "製弓" : (:do_aca:) ,
        "條件" : (:do_acb:) ,       
]));
        add_action("do_act","act");
        add_action("do_aca","aca");
        set("combat_exp",1000000);
        setup();
        add_money("silver",1);
}
int accept_fight(object who)
{
 return notify_fail("老人說:都不會敬老尊賢嗎?，真沒教養的人。\n");
}
void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) 

        {
        remove_call_out("greeting");
        call_out("greeting",2,obj);
        }
}
void greeting(object ob)
{
        command("say 有事嗎? ");
}
  string do_act()
{
        command("say 我認識，當初他那把李廣弓就是我做給他的。 ");
        command("say 不過我現在沒在「製弓」了，年事已高囉。");           
}

string do_aca()
{
    command("say 什麼?李廣要我幫你做把弓?!");
    command("say hmm");
    command("say 看在李廣的面子上，就幫你做吧，不過可是有「條件」的。\n");
}
string do_acb()
{
  command("say 我很喜歡后羿身旁的那把落日弓，若你能幫我取回，必定製做最好的弓。");
  command("say 來做為謝禮。\n");
}
string do_acc()
{
command("say 你可真厲害，我這個封號很久沒用囉。");
command("say 說起來我這個封號只有「李廣」一位知道而已呀。\n");
}
