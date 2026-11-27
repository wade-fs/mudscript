// d/city/center/clinic.c
// 杏林醫館 (濁氣清心散、試藥童緩衝路徑 C)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・杏林醫館");
    set_long("府城最大的草藥診所與濟世堂口，空氣中瀰漫著清冽的煎藥苦甘之氣。\n"
             "整面牆壁嵌滿了數百個百眼藥斗，分類存放著來自青河縣與大荒各地的靈草散劑。\n"
             "館主白先生正坐在診案前為病患切脈行針。此處常年供應【清心散】(buy pill)\n"
             "供修士百姓淨化紅塵濁氣，亦可申請充任試藥童 (ask bai about 試藥) 領取合法腰牌。\n"
             "已考取杏林坐堂資格者可在此公開坐診 (diagnose / 坐診)。\n"
             "東面穿過穿廊可通往金石學塾。\n");

    set_exits(([
        "east": "/d/city/center/academy.c",
    ]));

    set("is_outdoor", 0);
    set_touch("default", HIG "榆木診案被幾代醫者磨得溫潤光滑，百眼藥斗的銅環微涼。" NOR);
    set_smell("default", CYN "濃烈卻令人心安的甘草、紫蘇、連翹與沸騰藥湯的清苦氣息縈繞不散。" NOR);
    set_listen("default", WHT "後堂搗藥鐵臼傳來規律的『叮噹』撞擊聲，偶爾夾雜病患輕咳與白先生切脈問診的低語。" NOR);

    mapping diag_rule = ([
        "require_qualification": "medical",
        "action_label": "公開坐堂行醫",
        "sp_cost": 10,
        "sensory_msg": HIG "你淨手後端坐於杏林副案，三指搭上病患寸關尺脈門，依草木歸經寫下平順清方的同時，分明感觸到城中紅塵濁氣在病人血脈裡的微弱沉積。" NOR,
        "train_stat": ([ "int": 10, "per": 10 ]),
        "exp_gain": 12
    ]);
    add_action_rule("diagnose", diag_rule);
    add_action_rule("坐診", diag_rule);

    spawn_npc("/clone/npc/center_doctor_bai.c");
}

void init() {
    ::init();
    add_action("do_clinic_treat", "treat");
    add_action("do_clinic_treat", "診治");
}

int do_clinic_treat(string arg) {
    object me = this_player();
    if (!me) return 0;
    object city_d = load_object(CITY_D);
    mapping tier = city_d ? city_d->query_social_tier(me) : ([]);
    if (mapp(tier) && tier["tier_id"] == "unregistered_vagrant") {
        write(HIR "藥房管事攔住你皺眉道：「杏林內堂診治須查驗居留保書或路引名籍，無籍散客請出南關往【施藥義棚】取粗湯罷！」\n" NOR);
        return 1;
    }
    int fee = 50;
    if (me->query("money") < fee) {
        write(YEL "醫館夥計翻開帳簿道：「內城杏林精方連藥帶診須五十文現錢，盤纏不夠可先去南關外施藥義棚湊合著喝。」\n" NOR);
        return 1;
    }
    me->add_money(-fee);
    if (city_d) city_d->cleanse_turbidity(me, 15);
    me->add(VITAL_KEE, 60);
    me->add(VITAL_SEN, 40);
    write(HIG "你繳足五十文診金，白先生親手施以金針過脈並賜下一貼清心靈草方。（氣血 +60、神識 +40、紅塵濁氣減輕）\n" NOR);
    return 1;
}
