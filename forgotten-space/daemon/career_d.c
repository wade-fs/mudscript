// daemon/career_d.c
// 《遺忘的世界》三大道統鏈式閉合任務守護進程 (CAREER_D)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping CHAIN_INFO = ([
    "wu": ([
        "name": "物修之鏈・百工互生環",
        "stat": "dex/str/per",
        "stages": ([
            1: "【第 1 階・接應礦坑】前往北崖黑石古礦坑，向老礦工魯大山詢問 (ask lu about 任務) 接應受困礦工。",
            2: "【第 2 階・採藥療毒】前往南谷溪灘採集晨露草 (gather)，交由草廬葛半仙配製解毒淬火藥液。",
            3: "【第 3 階・回爐淬火】將配得的靈藥送回老鐵匠鋪交付阿鐵。",
            4: "【第 4 階・開爐鍛造】在老鐵匠鋪手持鐵錘，拉動風箱、鍛打粗礦胚料 (strike ore)，完成百工閉環！"
        ])
    ]),
    "li": ([
        "name": "力修之鏈・血戰生機環",
        "stat": "str/con/kee",
        "stages": ([
            1: "【第 1 階・荒林警備】向獵戶哨亭趙老獵詢問 (ask zhao about 任務) 領取荒林戒備指令。",
            2: "【第 2 階・陷阱追蹤】前往東面荒林調校獵戶陷阱 (trap)，追蹤深山濁血 (track)，排查獸群暴動。",
            3: "【第 3 階・血肉抗煞】前往溪灘尋找張屠戶，以剔骨刀抗煞磨刀，分理異獸筋骨皮甲。",
            4: "【第 4 階・搏殺傳功】攜獸皮血信返回獵戶哨亭回報趙老獵，淬礪氣血，受傳大荒搏殺精義！"
        ])
    ]),
    "fa": ([
        "name": "法修之鏈・天人共鳴環",
        "stat": "int/spi/sen",
        "stages": ([
            1: "【第 1 階・氣機排查】向三清偏殿枯木老道詢問 (ask kumu about 任務) 請受天道法旨。",
            2: "【第 2 階・溪灘洗心】在南谷溪灘掬水洗心 (wash)，並在史前殘碑上拓印天道符文 (tuoyin stele)。",
            3: "【第 3 階・孤壇觀星】登上道觀後山迎風孤岩，於殘壇之上打坐入定 (meditate) 或仰觀星軌 (stargaze)。",
            4: "【第 4 階・撫頂傳道】返回三清殿向枯木老道回報觀星感悟，由老道推演天機、撫頂點化！"
        ])
    ])
]);

void create() {
    ::create();
}

int query_chain_stage(object who, string path_type) {
    if (!who) return 0;
    int st = who->query("task_chain/" + path_type + "_stage");
    if (st <= 0) st = 1;
    return st;
}

string query_stage_desc(string path_type, int stage) {
    if (!CHAIN_INFO[path_type]) return "";
    mapping stages = CHAIN_INFO[path_type]["stages"];
    if (!stages || !stages[stage]) return "";
    return stages[stage];
}

string query_chain_name(string path_type) {
    if (!CHAIN_INFO[path_type]) return "";
    return CHAIN_INFO[path_type]["name"];
}

void advance_chain_stage(object who, string path_type) {
    if (!who) return;
    int current = query_chain_stage(who, path_type);
    current++;
    if (current > 4) {
        // 完成一整輪閉環，重置為 1，並發放傳承聲望與獎勵
        current = 1;
        who->add("affinity/" + path_type, 10);
        who->add("exp", 150);
        tell_object(who, HIY "\n【✨ 恭喜完成一整輪「" + query_chain_name(path_type) + "」歷練！】\n" +
                             "你的道統領會進一步加深，獲得 150 點歷練經驗，【" + path_type + " 道統傳承親和度 +10】！\n\n" NOR);
    } else {
        tell_object(who, HIG "【鏈式任務推進】" + query_stage_desc(path_type, current) + "\n" NOR);
    }
    who->set("task_chain/" + path_type + "_stage", current);
}

string query_all_chains_status(object who) {
    if (!who) return "";
    string res = HIW "=== 黑石鋪三大道統・鏈式循環任務進度 ===\n" NOR;
    string *paths = ({ "wu", "li", "fa" });
    foreach (string p in paths) {
        int st = query_chain_stage(who, p);
        int aff = who->query("affinity/" + p);
        res += sprintf(CYN "【%s】" NOR " (傳承親和: %d)\n  %s\n",
            query_chain_name(p), aff, query_stage_desc(p, st));
    }
    res += HIW "=======================================\n" NOR;
    return res;
}
