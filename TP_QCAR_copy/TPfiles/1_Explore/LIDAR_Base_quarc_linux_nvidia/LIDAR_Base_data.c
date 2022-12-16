/*
 * LIDAR_Base_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LIDAR_Base".
 *
 * Model version              : 5.1
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Oct 19 08:21:56 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LIDAR_Base.h"
#include "LIDAR_Base_private.h"

/* Block parameters (default storage) */
P_LIDAR_Base_T LIDAR_Base_P = {
  /* Variable: X_ic
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Variable: Y_ic
   * Referenced by: '<S7>/Integrator1'
   */
  0.0,

  /* Variable: vehicle_length
   * Referenced by:
   *   '<S7>/1//L'
   *   '<S7>/Gain'
   */
  0.256,

  /* Variable: yaw_ic
   * Referenced by: '<S7>/Integrator2'
   */
  -1.5707963267948966,

  /* Mask Parameter: BodyFramePolarPlot_maximum_rho
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  4.0,

  /* Mask Parameter: BodyFramePolarPlot_maximum_thet
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  360.0,

  /* Mask Parameter: BodyFramePolarPlot_minimum_rho
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.0,

  /* Mask Parameter: BodyFramePolarPlot_minimum_thet
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.0,

  /* Mask Parameter: BodyFramePolarPlot_direction
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Mask Parameter: BodyFramePolarPlot_update_rate
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Mask Parameter: BodyFramePolarPlot_zero_locatio
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  2,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<Root>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite1_other_channels
   * Referenced by: '<Root>/HIL Write1'
   */
  1000U,

  /* Mask Parameter: HILWrite1_pwm_channels
   * Referenced by: '<Root>/HIL Write1'
   */
  0U,

  /* Expression: 0
   * Referenced by: '<S11>/Constant'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize1'
   */
  36621.09375,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: timing_budget
   * Referenced by: '<S4>/Ranging Sensor'
   */
  0.033,

  /* Expression: measurement_period
   * Referenced by: '<S4>/Ranging Sensor'
   */
  0.0001,

  /* Expression: max_interpolated_distance
   * Referenced by: '<S4>/Ranging Sensor'
   */
  0.0,

  /* Expression: max_interpolated_angle
   * Referenced by: '<S4>/Ranging Sensor'
   */
  5.0,

  /* Expression: pi*(0:0.5:359.95)/180
   * Referenced by: '<S4>/Constant1'
   */
  { 0.0, 0.0087266462599716477, 0.017453292519943295, 0.026179938779914941,
    0.034906585039886591, 0.043633231299858237, 0.052359877559829883,
    0.061086523819801536, 0.069813170079773182, 0.078539816339744828,
    0.087266462599716474, 0.09599310885968812, 0.10471975511965977,
    0.11344640137963143, 0.12217304763960307, 0.1308996938995747,
    0.13962634015954636, 0.14835298641951802, 0.15707963267948966,
    0.16580627893946129, 0.17453292519943295, 0.18325957145940461,
    0.19198621771937624, 0.20071286397934787, 0.20943951023931953,
    0.21816615649929119, 0.22689280275926285, 0.23561944901923448,
    0.24434609527920614, 0.2530727415391778, 0.26179938779914941,
    0.27052603405912107, 0.27925268031909273, 0.28797932657906439,
    0.29670597283903605, 0.30543261909900765, 0.31415926535897931,
    0.32288591161895097, 0.33161255787892258, 0.34033920413889424,
    0.3490658503988659, 0.3577924966588375, 0.36651914291880922,
    0.37524578917878082, 0.38397243543875248, 0.39269908169872414,
    0.40142572795869574, 0.41015237421866746, 0.41887902047863906,
    0.42760566673861072, 0.43633231299858238, 0.445058959258554,
    0.4537856055185257, 0.46251225177849731, 0.47123889803846897,
    0.47996554429844063, 0.48869219055841229, 0.49741883681838389,
    0.50614548307835561, 0.51487212933832716, 0.52359877559829882,
    0.53232542185827048, 0.54105206811824214, 0.5497787143782138,
    0.55850536063818546, 0.56723200689815712, 0.57595865315812877,
    0.58468529941810032, 0.59341194567807209, 0.60213859193804364,
    0.6108652381980153, 0.619591884457987, 0.62831853071795862,
    0.63704517697793028, 0.64577182323790194, 0.6544984694978736,
    0.66322511575784515, 0.67195176201781692, 0.68067840827778847,
    0.68940505453776013, 0.69813170079773179, 0.70685834705770345,
    0.715584993317675, 0.72431163957764677, 0.73303828583761843,
    0.74176493209759009, 0.75049157835756164, 0.7592182246175333,
    0.767944870877505, 0.77667151713747673, 0.78539816339744828,
    0.79412480965741994, 0.80285145591739149, 0.81157810217736315,
    0.82030474843733492, 0.82903139469730658, 0.83775804095727813,
    0.84648468721724979, 0.85521133347722145, 0.86393797973719322,
    0.87266462599716477, 0.88139127225713643, 0.890117918517108,
    0.89884456477707964, 0.90757121103705141, 0.91629785729702307,
    0.92502450355699462, 0.93375114981696627, 0.94247779607693793,
    0.95120444233690948, 0.95993108859688125, 0.96865773485685291,
    0.97738438111682457, 0.98611102737679612, 0.99483767363676778,
    1.0035643198967394, 1.0122909661567112, 1.0210176124166828,
    1.0297442586766543, 1.0384709049366261, 1.0471975511965976,
    1.0559241974565694, 1.064650843716541, 1.0733774899765127,
    1.0821041362364843, 1.0908307824964558, 1.0995574287564276,
    1.1082840750163994, 1.1170107212763709, 1.1257373675363425,
    1.1344640137963142, 1.143190660056286, 1.1519173063162575,
    1.1606439525762291, 1.1693705988362006, 1.1780972450961724,
    1.1868238913561442, 1.1955505376161157, 1.2042771838760873,
    1.2130038301360591, 1.2217304763960306, 1.2304571226560022,
    1.2391837689159739, 1.2479104151759457, 1.2566370614359172,
    1.2653637076958888, 1.2740903539558606, 1.2828170002158323,
    1.2915436464758039, 1.3002702927357754, 1.3089969389957472,
    1.3177235852557188, 1.3264502315156903, 1.3351768777756621,
    1.3439035240356338, 1.3526301702956054, 1.3613568165555769,
    1.3700834628155485, 1.3788101090755203, 1.387536755335492,
    1.3962634015954636, 1.4049900478554351, 1.4137166941154069,
    1.4224433403753785, 1.43116998663535, 1.4398966328953218, 1.4486232791552935,
    1.4573499254152653, 1.4660765716752369, 1.4748032179352084,
    1.4835298641951802, 1.4922565104551517, 1.5009831567151233,
    1.509709802975095, 1.5184364492350666, 1.5271630954950381, 1.53588974175501,
    1.5446163880149817, 1.5533430342749535, 1.562069680534925,
    1.5707963267948966, 1.5795229730548681, 1.5882496193148399,
    1.5969762655748114, 1.605702911834783, 1.6144295580947547,
    1.6231562043547263, 1.6318828506146983, 1.6406094968746698,
    1.6493361431346414, 1.6580627893946132, 1.6667894356545847,
    1.6755160819145563, 1.684242728174528, 1.6929693744344996,
    1.7016960206944711, 1.7104226669544429, 1.7191493132144144,
    1.7278759594743864, 1.736602605734358, 1.7453292519943295,
    1.7540558982543013, 1.7627825445142729, 1.7715091907742444,
    1.780235837034216, 1.7889624832941877, 1.7976891295541593,
    1.8064157758141308, 1.8151424220741028, 1.8238690683340744,
    1.8325957145940461, 1.8413223608540177, 1.8500490071139892,
    1.858775653373961, 1.8675022996339325, 1.8762289458939041,
    1.8849555921538759, 1.8936822384138474, 1.902408884673819, 1.911135530933791,
    1.9198621771937625, 1.9285888234537343, 1.9373154697137058,
    1.9460421159736774, 1.9547687622336491, 1.9634954084936207,
    1.9722220547535922, 1.9809487010135638, 1.9896753472735356,
    1.9984019935335071, 2.0071286397934789, 2.0158552860534509,
    2.0245819323134224, 2.033308578573394, 2.0420352248333655,
    2.0507618710933371, 2.0594885173533086, 2.0682151636132806,
    2.0769418098732522, 2.0856684561332237, 2.0943951023931953,
    2.1031217486531673, 2.1118483949131388, 2.1205750411731104,
    2.1293016874330819, 2.1380283336930535, 2.1467549799530254,
    2.155481626212997, 2.1642082724729685, 2.17293491873294, 2.1816615649929116,
    2.1903882112528836, 2.1991148575128552, 2.2078415037728267,
    2.2165681500327987, 2.2252947962927703, 2.2340214425527418,
    2.2427480888127134, 2.2514747350726849, 2.2602013813326565,
    2.2689280275926285, 2.2776546738526, 2.286381320112572, 2.2951079663725436,
    2.3038346126325151, 2.3125612588924866, 2.3212879051524582,
    2.3300145514124297, 2.3387411976724013, 2.3474678439323733,
    2.3561944901923448, 2.3649211364523164, 2.3736477827122884, 2.38237442897226,
    2.3911010752322315, 2.399827721492203, 2.4085543677521746,
    2.4172810140121466, 2.4260076602721181, 2.4347343065320897,
    2.4434609527920612, 2.4521875990520328, 2.4609142453120043,
    2.4696408915719763, 2.4783675378319479, 2.48709418409192, 2.4958208303518914,
    2.5045474766118629, 2.5132741228718345, 2.522000769131806,
    2.5307274153917776, 2.5394540616517491, 2.5481807079117211,
    2.5569073541716927, 2.5656340004316647, 2.5743606466916362,
    2.5830872929516078, 2.5918139392115793, 2.6005405854715509,
    2.6092672317315224, 2.6179938779914944, 2.626720524251466,
    2.6354471705114375, 2.6441738167714091, 2.6529004630313806,
    2.6616271092913526, 2.6703537555513241, 2.6790804018112957,
    2.6878070480712677, 2.6965336943312392, 2.7052603405912108,
    2.7139869868511823, 2.7227136331111539, 2.7314402793711254,
    2.740166925631097, 2.748893571891069, 2.7576202181510405, 2.7663468644110125,
    2.7750735106709841, 2.7838001569309556, 2.7925268031909272,
    2.8012534494508987, 2.8099800957108703, 2.8187067419708423,
    2.8274333882308138, 2.8361600344907854, 2.8448866807507569,
    2.8536133270107289, 2.8623399732707, 2.871066619530672, 2.8797932657906435,
    2.8885199120506155, 2.8972465583105871, 2.9059732045705586,
    2.9146998508305306, 2.9234264970905017, 2.9321531433504737,
    2.9408797896104448, 2.9496064358704168, 2.9583330821303884,
    2.9670597283903604, 2.9757863746503315, 2.9845130209103035,
    2.9932396671702755, 3.0019663134302466, 3.0106929596902186, 3.01941960595019,
    3.0281462522101616, 3.0368728984701332, 3.0455995447301052,
    3.0543261909900763, 3.0630528372500483, 3.07177948351002, 3.0805061297699914,
    3.0892327760299634, 3.0979594222899349, 3.1066860685499069,
    3.115412714809878, 3.12413936106985, 3.1328660073298211, 3.1415926535897931,
    3.1503192998497647, 3.1590459461097362, 3.1677725923697082,
    3.1764992386296798, 3.1852258848896517, 3.1939525311496229,
    3.2026791774095948, 3.211405823669566, 3.2201324699295379,
    3.2288591161895095, 3.2375857624494815, 3.2463124087094526,
    3.2550390549694246, 3.2637657012293966, 3.2724923474893677,
    3.2812189937493397, 3.2899456400093112, 3.2986722862692828,
    3.3073989325292543, 3.3161255787892263, 3.3248522250491974,
    3.3335788713091694, 3.3423055175691405, 3.3510321638291125,
    3.3597588100890845, 3.3684854563490561, 3.377212102609028,
    3.3859387488689991, 3.3946653951289711, 3.4033920413889422,
    3.4121186876489142, 3.4208453339088858, 3.4295719801688573,
    3.4382986264288289, 3.4470252726888009, 3.4557519189487729,
    3.464478565208744, 3.473205211468716, 3.4819318577286871, 3.4906585039886591,
    3.4993851502486306, 3.5081117965086026, 3.5168384427685737,
    3.5255650890285457, 3.5342917352885168, 3.5430183815484888,
    3.5517450278084608, 3.5604716740684319, 3.5691983203284039,
    3.5779249665883754, 3.5866516128483474, 3.5953782591083185,
    3.6041049053682905, 3.6128315516282616, 3.6215581978882336,
    3.6302848441482056, 3.6390114904081772, 3.6477381366681487,
    3.6564647829281203, 3.6651914291880923, 3.6739180754480634,
    3.6826447217080354, 3.6913713679680069, 3.7000980142279785, 3.70882466048795,
    3.717551306747922, 3.726277953007894, 3.7350045992678651, 3.7437312455278371,
    3.7524578917878082, 3.76118453804778, 3.7699111843077517, 3.7786378305677237,
    3.7873644768276948, 3.7960911230876668, 3.8048177693476379, 3.81354441560761,
    3.8222710618675819, 3.830997708127553, 3.839724354387525, 3.8484510006474966,
    3.8571776469074686, 3.8659042931674397, 3.8746309394274117,
    3.8833575856873828, 3.8920842319473548, 3.9008108782073263,
    3.9095375244672983, 3.91826417072727, 3.9269908169872414, 3.9357174632472134,
    3.9444441095071845, 3.9531707557671565, 3.9618974020271276,
    3.9706240482870996, 3.9793506945470711, 3.9880773408070431,
    3.9968039870670142, 4.0055306333269858, 4.0142572795869578, 4.02298392584693,
    4.0317105721069018, 4.0404372183668729, 4.0491638646268449,
    4.057890510886816, 4.066617157146788, 4.0753438034067591, 4.0840704496667311,
    4.0927970959267022, 4.1015237421866741, 4.1102503884466461,
    4.1189770347066172, 4.1277036809665892, 4.1364303272265612,
    4.1451569734865323, 4.1538836197465043, 4.1626102660064763,
    4.1713369122664474, 4.1800635585264194, 4.1887902047863905,
    4.1975168510463625, 4.2062434973063345, 4.2149701435663056,
    4.2236967898262776, 4.2324234360862487, 4.2411500823462207,
    4.2498767286061918, 4.2586033748661638, 4.2673300211261358,
    4.2760566673861069, 4.2847833136460789, 4.2935099599060509,
    4.3022366061660229, 4.310963252425994, 4.319689898685966, 4.3284165449459371,
    4.3371431912059091, 4.34586983746588, 4.3545964837258522, 4.3633231299858233,
    4.3720497762457953, 4.3807764225057673, 4.3895030687657384, 4.39822971502571,
    4.4069563612856815, 4.4156830075456535, 4.4244096538056255,
    4.4331363000655974, 4.4418629463255686, 4.4505895925855405,
    4.4593162388455116, 4.4680428851054836, 4.4767695313654556,
    4.4854961776254267, 4.4942228238853987, 4.50294947014537, 4.5116761164053418,
    4.5204027626653129, 4.5291294089252849, 4.5378560551852569,
    4.546582701445228, 4.5553093477052, 4.564035993965172, 4.572762640225144,
    4.5814892864851151, 4.5902159327450871, 4.5989425790050582, 4.60766922526503,
    4.6163958715250013, 4.6251225177849733, 4.6338491640449444,
    4.6425758103049164, 4.6513024565648875, 4.6600291028248595,
    4.6687557490848315, 4.6774823953448026, 4.6862090416047746,
    4.6949356878647466, 4.7036623341247186, 4.71238898038469, 4.7211156266446617,
    4.7298422729046328, 4.7385689191646048, 4.7472955654245768,
    4.7560222116845479, 4.76474885794452, 4.773475504204491, 4.782202150464463,
    4.7909287967244341, 4.7996554429844061, 4.8083820892443772,
    4.8171087355043491, 4.8258353817643211, 4.8345620280242931,
    4.8432886742842651, 4.8520153205442362, 4.8607419668042082,
    4.8694686130641793, 4.8781952593241513, 4.8869219055841224,
    4.8956485518440944, 4.9043751981040655, 4.9131018443640375,
    4.9218284906240086, 4.9305551368839806, 4.9392817831439526,
    4.9480084294039237, 4.9567350756638957, 4.9654617219238677, 4.97418836818384,
    4.9829150144438108, 4.9916416607037828, 5.0003683069637539,
    5.0090949532237259, 5.017821599483697, 5.026548245743669, 5.035274892003641,
    5.0440015382636121, 5.0527281845235841, 5.0614548307835552,
    5.0701814770435272, 5.0789081233034983, 5.08763476956347, 5.0963614158234423,
    5.1050880620834143, 5.1138147083433854, 5.1225413546033574,
    5.1312680008633293, 5.1399946471233005, 5.1487212933832724,
    5.1574479396432436, 5.1661745859032155, 5.1749012321631866,
    5.1836278784231586, 5.19235452468313, 5.2010811709431017, 5.2098078172030728,
    5.2185344634630448, 5.2272611097230168, 5.2359877559829888,
    5.2447144022429608, 5.2534410485029319, 5.2621676947629039,
    5.270894341022875, 5.279620987282847, 5.2883476335428181, 5.29707427980279,
    5.3058009260627612, 5.3145275723227332, 5.3232542185827052,
    5.3319808648426763, 5.3407075111026483, 5.3494341573626194,
    5.3581608036225914, 5.3668874498825634, 5.3756140961425354,
    5.3843407424025065, 5.3930673886624785, 5.4017940349224505,
    5.4105206811824216, 5.4192473274423936, 5.4279739737023647,
    5.4367006199623367, 5.4454272662223078, 5.45415391248228, 5.4628805587422509,
    5.4716072050022229, 5.480333851262194, 5.489060497522166, 5.497787143782138,
    5.50651379004211, 5.5152404363020811, 5.523967082562053, 5.532693728822025,
    5.5414203750819961, 5.5501470213419681, 5.5588736676019392,
    5.5676003138619112, 5.5763269601218823, 5.5850536063818543,
    5.5937802526418263, 5.6025068989017974, 5.6112335451617694,
    5.6199601914217405, 5.6286868376817125, 5.6374134839416845,
    5.6461401302016565, 5.6548667764616276, 5.6635934227216, 5.6723200689815707,
    5.6810467152415427, 5.6897733615015138, 5.6985000077614867,
    5.7072266540214578, 5.7159533002814289, 5.7246799465414, 5.7334065928013729,
    5.742133239061344, 5.7508598853213151, 5.7595865315812871,
    5.7683131778412591, 5.7770398241012311, 5.7857664703612022,
    5.7944931166211742, 5.8032197628811462, 5.8119464091411173,
    5.8206730554010884, 5.8293997016610613, 5.8381263479210324,
    5.8468529941810035, 5.8555796404409746, 5.8643062867009474,
    5.8730329329609186, 5.88175957922089, 5.8904862254808625, 5.8992128717408336,
    5.9079395180008056, 5.9166661642607767, 5.9253928105207487,
    5.9341194567807207, 5.9428461030406918, 5.9515727493006629,
    5.9602993955606358, 5.9690260418206069, 5.977752688080578,
    5.9864793343405509, 5.995205980600522, 6.0039326268604931,
    6.0126592731204642, 6.0213859193804371, 6.0301125656404082, 6.03883921190038,
    6.0475658581603513, 6.0562925044203233, 6.0650191506802953,
    6.0737457969402664, 6.0824724432002393, 6.09119908946021, 6.0999257357201815,
    6.1086523819801526, 6.1173790282401255, 6.1261056745000966,
    6.1348323207600677, 6.14355896702004, 6.1522856132800117, 6.1610122595399828,
    6.1697389057999548, 6.1784655520599268, 6.1871921983198979, 6.19591884457987,
    6.204645490839841, 6.2133721370998138, 6.2220987833597849,
    6.2308254296197561, 6.2395520758797289, 6.2482787221397, 6.2570053683996711,
    6.2657320146596422, 6.2744586609196151 },

  /* Expression: line1_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line1_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.0, 0.447, 0.741 },

  /* Expression: marker1_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1.0,

  /* Expression: marker1_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.0, 0.447059, 0.741176 },

  /* Expression: marker1_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.0, 0.447059, 0.741176 },

  /* Expression: line2_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line2_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.85098, 0.32549, 0.0980392 },

  /* Expression: marker2_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker2_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.85098, 0.32549, 0.0980392 },

  /* Expression: marker2_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.85098, 0.32549, 0.0980392 },

  /* Expression: line3_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line3_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.929412, 0.694118, 0.12549 },

  /* Expression: marker3_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker3_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.929412, 0.694118, 0.12549 },

  /* Expression: marker3_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.929412, 0.694118, 0.12549 },

  /* Expression: line4_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line4_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.494118, 0.184314, 0.556863 },

  /* Expression: marker4_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker4_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.494118, 0.184314, 0.556863 },

  /* Expression: marker4_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.494118, 0.184314, 0.556863 },

  /* Expression: line5_width
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  0.5,

  /* Expression: line5_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.466667, 0.67451, 0.188235 },

  /* Expression: marker5_size
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  6.0,

  /* Expression: marker5_edge_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.466667, 0.67451, 0.188235 },

  /* Expression: marker5_face_color
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  { 0.466667, 0.67451, 0.188235 },

  /* Expression: 0.2
   * Referenced by: '<Root>/Constant4'
   */
  0.2,

  /* Expression: 0.8
   * Referenced by: '<S8>/command saturation'
   */
  0.8,

  /* Expression: -0.8
   * Referenced by: '<S8>/command saturation'
   */
  -0.8,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Kff  (% // m//s)'
   */
  0.1,

  /* Expression: 25
   * Referenced by: '<S5>/Constant2'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator2'
   */
  0.0,

  /* Expression: 1/720/4
   * Referenced by: '<S3>/counts to rotations'
   */
  0.00034722222222222224,

  /* Expression: (13*19)/(70*37)
   * Referenced by: '<S3>/gear ratios'
   */
  0.095366795366795362,

  /* Expression: 2*pi
   * Referenced by: '<S3>/rot//s to rad//s'
   */
  6.2831853071795862,

  /* Expression: 0.0342
   * Referenced by: '<S3>/wheel radius'
   */
  0.0342,

  /* Expression: 0.1
   * Referenced by: '<S8>/Kp (% // m//s)'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Integrator1'
   */
  0.1,

  /* Expression: -0.1
   * Referenced by: '<S8>/Integrator1'
   */
  -0.1,

  /* Expression: 0.5
   * Referenced by: '<S8>/Motor_command  sat'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S8>/Motor_command  sat'
   */
  -0.5,

  /* Expression: -1
   * Referenced by: '<Root>/direction convention'
   */
  -1.0,

  /* Expression: 0.20
   * Referenced by: '<Root>/command saturation'
   */
  0.2,

  /* Expression: -0.20
   * Referenced by: '<Root>/command saturation'
   */
  -0.2,

  /* Expression: 0.0
   * Referenced by: '<Root>/Steering Bias'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant3'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S10>/Constant'
   */
  2.0,

  /* Expression: modulus
   * Referenced by: '<S5>/Unwrap 2^24'
   */
  1.6777215E+7,

  /* Expression: 0.1
   * Referenced by: '<S8>/Ki (% // m)  '
   */
  0.1,

  /* Computed Parameter: HILInitialize1_EIInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POModes
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize1_POConfiguration
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POAlignment
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POPolarity
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L1Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  5,

  /* Computed Parameter: BodyFramePolarPlot_L1Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L2Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L2Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: BodyFramePolarPlot_L3Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L3Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: BodyFramePolarPlot_L4Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L4Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: BodyFramePolarPlot_L5Style
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  1,

  /* Computed Parameter: BodyFramePolarPlot_L5Marker
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  14,

  /* Computed Parameter: HILInitialize1_AIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U },

  /* Computed Parameter: HILInitialize1_DIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
    39U, 40U, 41U, 42U },

  /* Computed Parameter: HILInitialize1_DOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  40U,

  /* Computed Parameter: HILInitialize1_EIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U, 2U, 3U, 4U },

  /* Computed Parameter: HILInitialize1_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 4U, 4U },

  /* Computed Parameter: HILInitialize1_POChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0U,

  /* Computed Parameter: HILInitialize1_OOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 1000U, 11000U, 11001U, 11002U, 11003U, 11004U, 11005U, 11006U, 11007U,
    11008U, 11009U, 11010U, 11011U },

  /* Computed Parameter: RangingSensor_Range
   * Referenced by: '<S4>/Ranging Sensor'
   */
  3U,

  /* Computed Parameter: HILInitialize1_Active
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_EIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_EIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_EIStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_EIEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_OOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOFinal
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: RangingSensor_Active
   * Referenced by: '<S4>/Ranging Sensor'
   */
  true,

  /* Computed Parameter: HILWrite1_Active
   * Referenced by: '<Root>/HIL Write1'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<Root>/HIL Read'
   */
  true,

  /* Computed Parameter: BodyFramePolarPlot_Mode
   * Referenced by: '<Root>/Body Frame  Polar Plot'
   */
  2U
};
