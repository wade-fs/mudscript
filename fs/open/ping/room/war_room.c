inherit ROOM;
void create ()
{
  set ("short", "戰功\兌換處");
  set ("long", @LONG

此處是用來兌換戰功的地方!!目前可以兌換的項目如下：
-------------------------------------------------------------
  項  目           單 位          所需戰功              兌換指令
01.最大值靈力         1                3               need_max_atman
02.最大值法力         1                3               need_max_mana
03.最大值內力         1                5               need_max_force
04.替身               1               80               need_standby
05.臂力屬性           1              120               need_str
06.膽識屬性           1              120               need_cor
07.容貌屬性           1              120               need_per
08.根骨屬性           1              120               need_con
09.悟性屬性           1              150               need_int
10.福緣屬性           1              150               need_kar
11.靈性屬性           1              200               need_spi
12.定力屬性           1              200               need_cps

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road1",
]));
  setup();
}

/*
void init()
{
  add_action("max_atman","need_max_atman");
  add_action("max_mana","need_max_mana");
  add_action("max_force","need_max_force");
  add_action("standby","need_standby");
  add_action("str","need_str");
  add_action("cor","need_cor");
  add_action("per","need_per");
  add_action("con","need_con");
  add_action("intt","need_int");
  add_action("kar","need_kar");
  add_action("cps","need_cps");
  add_action("spi","need_spi");
  add_action("meq","need_meq");
  add_action("godeq","need_godeq");
}

int max_atman()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 3) {
  me->add("war_kills",-3);
  me->add("max_atman",1);
log_file("clan/atman", sprintf("%s(%s)換取用三點戰功\換取了一點的靈力值\n"
   ,me->query("name"),me->query("id")));
  write("您用三點戰功\來增加一點最大的靈力值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int max_mana()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 3) {
  me->add("war_kills",-3);
  me->add("max_mana",1);
log_file("clan/mana", sprintf("%s(%s)換取用三點戰功\換取了一點的法力值\n"
   ,me->query("name"),me->query("id")));
  write("您用三點戰功\來增加一點最大的法力值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
int max_force()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 5) {
  me->add("war_kills",-5);
  me->add("max_force",1);
log_file("clan/force", sprintf("%s(%s)換取用五點戰功\換取了一點的內力值\n"
   ,me->query("name"),me->query("id")));
  write("您用五點戰功\來增加一點最大的內力值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
int standby()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 80) {
  me->add("war_kills",-80);
  me->add("standby",1);
log_file("clan/standby", sprintf("%s(%s)換取用八十點戰功\換取了一個替身\n"
   ,me->query("name"),me->query("id")));
  write("您用八十點戰功\來換取一個替身。\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
int str()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 120) {
  me->add("war_kills",-120);
  me->add("str",1);
log_file("clan/str", sprintf("%s(%s)換取用一百二十點戰功\換取了一點的臂力值\n"
   ,me->query("name"),me->query("id")));
  write("您用一百二十點戰功\來增加一點的臂力值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int cor()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 120) {
  me->add("war_kills",-120);
  me->add("cor",1);
log_file("clan/cor", sprintf("%s(%s)換取用一百二十點戰功\換取了一點的膽識值\n"
   ,me->query("name"),me->query("id")));
  write("您用一百二十點戰功\來增加一點的膽識值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int per()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 120) {
  me->add("war_kills",-120);
  me->add("per",1);
log_file("clan/per", sprintf("%s(%s)換取用一百二十點戰功\換取了一點的外表值\n"
   ,me->query("name"),me->query("id")));
  write("您用一百二十點戰功\來增加一點的外表屬性值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
int con()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 120) {
  me->add("war_kills",-120);
  me->add("con",1);
log_file("clan/con", sprintf("%s(%s)換取用一百二十點戰功\換取了一點的根骨值\n"
   ,me->query("name"),me->query("id")));
  write("您用一百二十點戰功\來增加一點的根骨值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
int intt()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 150) {
  me->add("war_kills",-150);
  me->add("int",1);
log_file("clan/int", sprintf("%s(%s)換取用一百五十點戰功\換取了一點的悟性值\n"
   ,me->query("name"),me->query("id")));
  write("您用一百五十點戰功\來增加一點的悟性值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int kar()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 150) {
  me->add("war_kills",-150);
  me->add("kar",1);
log_file("clan/kar", sprintf("%s(%s)換取用一百五十點戰功\換取了一點的福緣值\n"
   ,me->query("name"),me->query("id")));
  write("您用一百五十點戰功\來增加一點的福緣值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int cps()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 200) {
  me->add("war_kills",-200);
  me->add("cps",1);
log_file("clan/cps", sprintf("%s(%s)換取用二百點戰功\換取了一點的定力值\n"
   ,me->query("name"),me->query("id")));
  write("您用二百點戰功\來增加一點的定力值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int spi()
{
 object me = this_player();
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 200) {
  me->add("war_kills",-200);
  me->add("spi",1);
log_file("clan/spi", sprintf("%s(%s)換取用二百點戰功\換取了一點的靈力值\n"
   ,me->query("name"),me->query("id")));
  write("您用二百點戰功\來增加一點的靈力值\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
// 關掉用戰功換 meq and godeq by swy
// meq and godeq 將放至 area 上由 ppl k npc 得 by swy
/*
int meq()
{
 object me = this_player(),mid;
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 600) {
  me->add("war_kills",-600);
  mid=new("/autoload/blademan/mdragon");
  mid->move(me);
log_file("clan/meq", sprintf("%s(%s)換取用六百點戰功\換取魔龍型防具\n"
   ,me->query("name"),me->query("id")));
  write("您用六百點戰功\換取了魔龍型防具!!\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}

int godeq()
{
 object me = this_player(),mid;
 int war_value;
 war_value = me->query("war_kills");
 if (war_value > 1000) {
  me->add("war_kills",-1000);
  mid=new("/autoload/god/god_eq");
  mid->move(me);
log_file("clan/godeq", sprintf("%s(%s)換取用一千點戰功\換取天界型防具\n"
   ,me->query("name"),me->query("id")));
  write("您用一千點戰功\換取了天界型防具!!\n");
  return 1;
 }
 write("對不起!!您的戰功\值不夠了!!!\n");
 return 0;
}
*/
