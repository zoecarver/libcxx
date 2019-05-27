//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template <class UIntType, size_t w, size_t n, size_t m, size_t r,
//           UIntType a, size_t u, UIntType d, size_t s,
//           UIntType b, size_t t, UIntType c, size_t l, UIntType f>
// class mersenne_twister_engine;

// template<class Sseq> explicit mersenne_twister_engine(Sseq& q);

#include "test_macros.h"

#include <random>
#include <sstream>
#include <cassert>

void
test1()
{
    const char* a = "358595400 4166558815 2016177162 3414480257 "
    "4027494649 3722317195 1190532340 3212207148 "
    "3537847251 389019999 1098708832 3277907415 "
    "1946784350 3608286140 2091419822 2227407035 "
    "2229110723 1825348377 1276269279 314337202 "
    "3182935337 1313150029 3118776508 3707918501 "
    "1900972958 4054820954 3973178248 906260237 "
    "1403942218 3139931556 2807126524 3940936448 "
    "1316345796 631296613 2268418920 2914000794 "
    "3760588399 3226216036 880155129 4183611084 "
    "211541083 3755352858 1331383234 3036493096 "
    "937478630 2092170412 777784402 93392729 "
    "3644029210 1681392086 2427001226 3143870332 "
    "3703581502 2017505388 1706274541 1049329728 "
    "2452031492 3437261233 2581204087 1700889875 "
    "1652573881 2127047692 3778506964 1960741508 "
    "2739602360 3395905609 2123355622 3041272975 "
    "784200748 3558951522 1002787860 4063320888 "
    "1587315560 4042698976 659183308 3082256417 "
    "2808969567 2361418535 3468698782 750700970 "
    "2991209851 3581521382 962022878 2518967363 "
    "1476525873 3865977235 2128790058 2380326689 "
    "1396773405 312559410 1370621899 1154499924 "
    "2963101919 2182689761 2071851902 1661288848 "
    "2411351341 1362764020 1289894483 1951662807 "
    "701821506 552267185 2356648449 3949188503 "
    "1748307081 87795201 3718396254 4112205936 "
    "2819888864 73923733 2800033151 839258139 "
    "3801779069 3105962436 2111266436 1772784466 "
    "3692264298 4148810953 3147390749 3537518553 "
    "1695044978 1430225842 1252346204 3465285434 "
    "3970017763 2920658411 2805151132 290569815 "
    "3802301355 1493420394 1943029276 1667143611 "
    "1049665988 1710824905 220168517 3997946231 "
    "1014582791 4244598752 1147604069 2533886627 "
    "598679964 761521020 431779255 3745982038 "
    "768658283 3598262505 1765664789 279538641 "
    "715144305 2371628432 2655860083 1759010423 "
    "3568452003 1910107098 2801429529 3924547532 "
    "3862672436 3933725740 1764550618 130893617 "
    "1460692387 4135312761 2075529299 2880227367 "
    "944557368 4166665482 2627749235 3732013815 "
    "1595900818 1553312393 3529311831 3531462424 "
    "2431328342 4075369692 1609967709 3704537555 "
    "2067297464 397140475 920618678 2840795964 "
    "4202512837 1286017648 7035910 1057207826 "
    "2325188262 191593698 3697383848 3029712831 "
    "2073681914 163454681 1329637200 290077398 "
    "287239431 4205081522 1233889024 167173087 "
    "3267660257 3406068803 2382354609 1680046927 "
    "125183503 3559536309 3208900974 2912148541 "
    "2882879316 1937001086 2919729069 892928802 "
    "4141691387 2507406586 855548593 3418647837 "
    "4035646154 2410275591 248715645 3180757482 "
    "1880770722 362912336 2964920095 2319904154 "
    "1493655850 4240733030 1834485846 1696040454 "
    "3329457927 1865824694 847759208 1587231623 "
    "3757294772 1161601118 3630323833 3007722125 "
    "3726418007 2124238171 1205345 172659797 "
    "3040354211 885213338 1857049013 447922412 "
    "719906299 1370059380 1922204800 3960090489 "
    "1658822644 1529626863 1565927273 3537718771 "
    "2733237258 2180221377 921910745 2144937687 "
    "1727603895 1315635304 4023867791 2401834107 "
    "808854185 2408824497 343935326 185237544 "
    "746732759 2641236122 4283215329 743609415 "
    "1134726665 3892851319 1302851263 3473445597 "
    "1326817414 2702766508 1943179285 4025685468 "
    "932896770 199392138 2787362875 3450501893 "
    "3351567147 2461286528 2227605848 2993751114 "
    "3988215720 1320573368 2866560199 4153194990 "
    "3007120042 3260751955 3171763740 2111121243 "
    "3962825228 102681859 3368179132 802089147 "
    "4029273561 424939445 4178414761 2592125109 "
    "1960801088 2967746406 310701990 2364200202 "
    "1320507009 3474372480 784693947 2952246664 "
    "1891935330 2048385105 3530082191 3238151038 "
    "3293189141 1316053288 2087004409 740799958 "
    "1187748554 3607767334 1190185990 1408429481 "
    "657134359 221834425 3907725865 1068016389 "
    "1402423875 2598612116 2046886300 2345022518 "
    "1196081924 357783981 4013683598 463491626 "
    "3269206482 3332444286 886491955 2257342866 "
    "475911113 833576299 2893727564 2866985145 "
    "1413365115 2995166393 1486060436 161205225 "
    "3181728373 3056027137 2040371876 2182305146 "
    "3028448628 2214316977 1266227021 876938740 "
    "276477469 752158077 2182179045 1381698878 "
    "3424557652 666674427 968327842 2534296575 "
    "265105940 961112540 2641188117 2319139814 "
    "1750453329 3450138343 678025317 1477566458 "
    "3773796420 2933993832 3326042905 4084805260 "
    "444182455 255333481 785163068 2321290820 "
    "2893603234 3005520266 541104079 1383277090 "
    "2770755666 3764627833 583371929 2864949033 "
    "1487681116 1811788361 240329486 3094213377 "
    "958509875 2564379085 1636995945 2070894127 "
    "2139004232 1747850055 3841512327 3325011872 "
    "1161622604 639182193 3533652535 4022667522 "
    "761048999 3337743670 254221568 2784956233 "
    "2990252814 4207922787 275707208 261819597 "
    "2071467265 4034945770 1999813410 3038921100 "
    "2200194573 1328217451 2440612380 3862293692 "
    "2733976812 2750523058 2920082515 3809044908 "
    "4285231753 3131963297 3481602724 1396460739 "
    "2011767965 2481047764 2958452120 3044188618 "
    "2217236658 3448605566 757716104 1818279145 "
    "2641228144 1312649639 1194087684 3845229729 "
    "1747658356 874418803 1956637337 268670179 "
    "2083040240 2577671381 3375334655 2587828868 "
    "1383012799 3583445685 2594576715 3282337104 "
    "4257972751 3440488071 3129180313 1830891395 "
    "1594931092 2680778339 3984026324 1102770400 "
    "2315820258 1263467048 1133254110 2400676748 "
    "2251795328 1036154092 3313541051 2277356560 "
    "1477696003 1417117088 3968537402 1404882202 "
    "2011058180 4114080985 1727459502 4100235708 "
    "2334509310 2829432554 377936301 1519324520 "
    "3252826644 1193335837 1929125820 2165344238 "
    "4160556243 223340988 670907625 1485396519 "
    "936389509 3813712964 2706450987 3132506320 "
    "875886515 557088991 2854916639 2955496008 "
    "2881696287 265169077 3239923698 3649366121 "
    "4072165960 1233904959 225406526 1767368993 "
    "1894882500 2296582180 339255168 83200939 "
    "2958376148 4100205346 1991250823 3806183082 "
    "2691709980 2642354997 3024056146 1681065839 "
    "3438299684 1638853652 362567001 2307868899 "
    "988801086 1342833399 2303298376 1500039911 "
    "765489391 4080464497 4155444368 980472018 "
    "2026981853 3460406995 391970367 667377014 "
    "4177754853 2657468948 3560690175 3030464357 "
    "2948380657 1208800977 2316451404 4001932203 "
    "1977856863 4265848271 3116200050 3037586215 "
    "1335232764 930230766 1026089249 2482219415 "
    "2613853154 1854543497 2909555107 3862874043 "
    "2609355500 907364682 383900687 358164223 "
    "232347546 2536276737 3118482806 1254103998 "
    "2357334077 1204777304 1996643329 4046232717 "
    "2570520290 3173323380 1201411457 2361883023 "
    "806087062 2984143714 2355127569 864220085 "
    "1787696713 1182652984 4200065581 100722519 "
    "2380458669 2429592313 2618338302 1236529564 "
    "1747130196 3711661325 1114068102 510380433 "
    "93703089 2277774664 3220741441 1577998569 "
    "2816701900 4206763045 2495239107 4080390459 "
    "1307072677 20360728 1468385549 96049834 "
    "3630657447 2809517346 3396111678 3043831060 "
    "673178359 4256729562 1755211210 1969834535 "
    "498315110 3717726302 1544859987 2239930949 "
    "1595372585 294525219 3961637067 3591840665 "
    "3324896933 2300077772 721255886 4197934760 "
    "1468866696 2184812884 628246683 3385113037 "
    "3041166140 3948531843 1176600829 228286131 "
    "2447397608 712235937 3332826819 2676980703 "
    "4019468871 1952389952 1202638254 3625447051";
    unsigned as[] = {3, 5, 7};
    std::seed_seq sseq(as, as+3);
    std::mt19937 e1(sseq);
    std::ostringstream os;
    os << e1;
    assert(os.str() == a);
}

void
test2()
{
    const char* a = "17895233847644109640 14665081038668852234 15987230621890949369 "
    "13796324649827964148 1670828176732799955 14078505147839608672 "
    "15497470967856861790 9566640372296747182 7839811585250789315 "
    "1350068003782415071 5639936432479386921 15925388701147119804 "
    "17415323390466493342 3892358083553387400 13485903346102334794 "
    "16926193162581531132 2711398308226914244 12515538113016451944 "
    "13856492368211347055 17968472785843263993 16129117710261673051 "
    "13041638543181171650 8985803498136324582 401118717516975186 "
    "7221524024767248666 13502820261231663498 8665119664667372350 "
    "4506836866186850029 14762924585995667460 7305266389803732087 "
    "9135600275824854713 8421320656548229332 14585303533697565624 "
    "13062167967956981222 15285580395823625260 17451830328116466708 "
    "17363259891080004456 13238190509560321740 10142215382802200927 "
    "3224236118694175902 15382517208605932923 10818882444738383326 "
    "16604245792882032433 10223425285179753002 1342432445403828765 "
    "4958539418185107403 9374581143772158175 7135181273441366910 "
    "5853026900476841261 8382327930174454355 2371969498930803266 "
    "16961635468480846337 377077518789053577 17661790013255465310 "
    "317500018453124832 3604586262706855295 13340007089026272125 "
    "7614051306438090372 17819007364113857386 15193526497275633437 "
    "6142773218979108210 14883287611587512668 12544132362002344419 "
    "1247987855434921372 6414191755211735979 7160327288923375132 "
    "7347937017206972868 17171048313531629893 18230412825496997383 "
    "10882960195884354661 3270707876715241884 16088870345045208503 "
    "15454419782166694763 1200609322828949525 10186066554418904177 "
    "7554892242763986291 8203847521335919011 16855803304338943001 "
    "16895223408596071476 562183806034700250 17761033068687156643 "
    "12370482348384718931 17895691979506634040 16028877286272943475 "
    "6671425930002400146 15167515621662197335 17503579548680921174 "
    "15910867647138768989 1705705354110203064 12201125760909412022 "
    "5523403744441352645 4540673037752294406 822888669354888870 "
    "13012517529113958824 702032511346794490 1245872939048413008 "
    "18060687614291143943 718002942670251776 14628954120078526945 "
    "7215746609592654001 15288092036204733967 12507582747898016110 "
    "8319356319569362772 3835100005166188461 10769229288786702843 "
    "14682980657311687345 10352054841727718090 13661249361946024317 "
    "1558696616315734178 9963912474249467679 18213809676410642730 "
    "7284438284457478230 8013656044128665351 6817107912809760616 "
    "4989038816564331700 12918068165960947833 9123533477086273623 "
    "741568181450204257 3801962339733348259 1923812112542486965 "
    "5884360231397942779 17008459141377852544 6569697353326895092 "
    "15194386425456240489 9363979514988323850 9212437218544795097 "
    "5650610605870621879 10315798944006232463 10345822437227504297 "
    "795589193815296350 11344022765750598871 3193778122705907169 "
    "16719669104430190089 14918335244853046975 11608293761910939782 "
    "17290187430985633813 856382712722415618 14819792788008454203 "
    "10571145147196955435 12858063129221173592 5671819431516788648 "
    "17837836658827607239 14004823010100183722 9067196699747632668 "
    "441015230260308492 3444946658209715644 1825101023084664281 "
    "11133092574473850025 12746373758552339264 10154162549097295782 "
    "14922316177042921089 12679802872389794491 8797747037480461410 "
    "13907752811248535439 5652405835046458389 3181711594575177977 "
    "15495242712294857418 6049158560807439366 952771601159099159 "
    "4587095466254740009 11160954054611782211 10071795025240457628 "
    "1536670498623767300 1990681379653546894 14312739227381277138 "
    "9695213786215402291 3580182943401628617 12313607438786545484 "
    "12864141705426648443 692371170805382036 13125536612285239925 "
    "9372929234002877092 9510419002221032820 3766423210161674061 "
    "3230494342413727261 5934351496112072933 2863344864469097044 "
    "10884720908958139042 4127946927340597780 9960629658622711061 "
    "14818231351611083857 6346099615454582885 12601407558879514692 "
    "17544105005554819865 1096648950913019831 9969868157190185788 "
    "12908611252828823970 5941129863397152719 16168953427117105234 "
    "12304862402025196697 7781571759256122972 13289545261301048078 "
    "11013924305579914035 8894422550580466537 7506958826675805512 "
    "14280817252893250439 2745266616282182732 17277225453205013047 "
    "14335499905842065319 11961295941780577536 18072890757248426766 "
    "1124506606842606920 17329960125355005185 13052066741624159010 "
    "5704650516221677069 16588425097127709212 11813406583737887980 "
    "16359723311775411283 13451679937172566665 5997753207634594468 "
    "10656019008205694109 13074690560123889048 14811648124990806194 "
    "7809449463531558024 5637787273252434288 16515135932856030468 "
    "3755600163640125044 1153929634172103321 11071014283313196016 "
    "11114640359080035583 15390782025450330559 14097530518721927499 "
    "14776783751481098767 7863618667181998233 11513855295425132436 "
    "4736362806980864724 5426549653049482466 10310828122060887518 "
    "4450247941008370560 9781171949844602811 6086471549040450051 "
    "6033923116291003194 17669843285681524740 17610378273478865070 "
    "12152320288002263294 6525449125788834221 5125338396312613396 "
    "9300082688721166268 959242243476884691 6379729471368150249 "
    "16379772457647614853 13454012201619761707 2392678998182524851 "
    "12693758700673471007 1138892516507202079 15673908144065302514 "
    "5299581449349386824 7590792025124859454 9863745357571267780 "
    "357345312340746112 17610247870912740564 16347431861769737095 "
    "11348828299228888092 7220122803951857490 7038822841708464676 "
    "9912221445023094105 5767425533670320190 6442622362743049032 "
    "17525461567869579503 4211095256108567696 14862334876401617373 "
    "2866362449624104511 11413742225973279461 13015745308569358847 "
    "5191760666536228849 17188167935010684492 18321678815621002079 "
    "13046333455321624690 3995310719038261500 10661051209947341089 "
    "7965203671238327266 16590917686161852835 3897101637344795372 "
    "1538303624766151695 10893225639252940698 5386335660311332214 "
    "5174479122000384061 17378437193516866561 13629320139302700770 "
    "10144210341964027265 12816799659000064406 3711797003976467729 "
    "5079455890584507977 432599929275804205 10435019529328454317 "
    "5310854040535477246 15941464006450157396 2192067269367387270 "
    "9782967689631091633 6777452250210540865 18067909703113078220 "
    "17525143578810667971 87448662189824165 412530897284614413 "
    "12066785122245373863 13073154860645125438 18282514257379582711 "
    "8460374908111578570 15967512883067334502 9620430172798103891 "
    "1264976185047610409 15426838192579528907 9878758812321441445 "
    "18029992505662864846 9383699886128308360 14538949787806484635 "
    "16958815135940772668 980481467951972605 3059030058898313960 "
    "11497544574740915907 8385450996898478663 15571176518627282350";
    unsigned as[] = {3, 5, 7};
    std::seed_seq sseq(as, as+3);
    std::mt19937_64 e1(sseq);
    std::ostringstream os;
    os << e1;
    assert(os.str() == a);
}

int main(int, char**)
{
    test1();
    test2();

  return 0;
}
