inherit NPC;
string do_act();
string do_acc();
string do_aca();
string do_acb();
string ask_tesin();
string ask_ball();
void create()
{
        set_name("柳繪心",({"liu hey-shun","liu"}));
        set("gender","女性");
        set("age",30);
        set("class","fighter");
        set("str",30);
        set("long","柳家標局第二掌門,也是柳淳風的女兒。 .\n");
        set("chat_chance",10);
        set("inquiry",([
        "龍鐵心" : (:ask_tesin:),
        "討伐" : (:do_act:) ,
        "報仇" : (:do_aca:) ,
        "寶庫" : (:do_acc:) ,
        "鄭雨橋" : (:do_acb:) ,
        "連陽劍晶珠" : (:ask_ball:),
        ]));
        add_action("do_act","act");
        add_action("do_acc","acc");
        add_action("do_aca","aca");
        add_action("do_acb","acb");
        set("combat_exp",1000000);
        setup();
        add_money("silver",1);
}
int accept_fight(object who)
{
 return notify_fail("柳繪心說:都不會憐香惜玉啊。\n");
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
        command("cry ");
}
  string do_act()
{
        command("say 唉.我爹是位正義之士。幾年前，聽到有位殘暴的人「鄭雨橋」 ");
        command("say 就義不容辭的帶領著鑣局弟子去替天行道。");
        command("say 他跟暴王戰了三天三夜，還是無法戰勝他，壯烈犧牲了。");
        command("say 結果還被暴王拿走了柳家「寶庫」的鑰匙。");
        command("say 我很想替父親「報仇」，無奈自己沒武功\，也不能拿回鑰匙。");
        command("say 我就是為了報仇，抱著必死的決心來到魔界，想找尋勇士。");
           
 }
string ask_tesin()
{
if (this_player()->query("quests/shasword")>=2 && this_player()->query("quests/shasword")<5)
{
this_player()->set("quests/shasword",5);
return ("十幾二十年前,就是龍大俠幫我們柳家重振雄風的..如果現在龍大俠還在的話..那不知該有多好.");
}
}
string do_acc()
{
command("say 那寶庫就在炎龍谷的裡面。");
        command("say 若能替我殺掉暴王，就自己拿著鑰匙取寶物去吧。");
}

string do_aca()
{
    command("say 只能怨自己沒武功\啦。");
    command("say 不過...只要有人替我報仇..那寶庫裡的寶物就當做謝禮吧。");
}

string do_acb()
{
   command("say 哼!殺父仇人，不共戴天。");
   command("say 他生性殘暴，愛殺生，已經有很多壯士為了討伐他而一去不回。");
   command("say 他現在是炎龍谷的谷主。");
}
string ask_ball()
{
 if(!this_player()->query_temp("swordtime"))
 {
  return ("對不起﹐你問的事我實在沒有印象。");
  }
 else
  {
  if (this_player()->query("class")=="swordsman" && this_player()->query_temp("swordquest/findball")==3)
    {
    this_player()->set_temp("swordquest/findball",4);
    return ("當初李夢枕曾經將連陽劍晶珠交給我，但是，被暴王搶走了!!\n");
   }
else return ("對不起﹐你問的事我實在沒有印象。");
 }
}
