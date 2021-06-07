#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_choice(void);
int atomic_number(void);
int atomic_symbol(void);
int atomic_name(void);
int atomic_weight(void);
int electronic_configuration(void);
int atomic_period(int);
char atomic_block(int);
char atomic_property(int);
int atomic_group(int);
char atomic_class(int);
void display(int, char, char, char, char, char);

char atoms[118][25] = {
    "Hydrogen",
    "Helium", 
    "Lithium",
    "Beryllium",
    "Boron",
    "Carbon",
    "Nitrogen",
    "Oxygen",
    "Fluorine",
    "Neon", 
    "Sodium",
    "Magnesium",
    "Aluminium",
    "Silicon",
    "Phosphorus",
    "Sulphur",
    "Chlorine",
    "Argon", 
    "Potassium",
    "Calcium",
    "Scandium",
    "Titanium",
    "Vanadium",
    "Chromium",
    "Manganese",
    "Iron",
    "Cobalt",
    "Nickel",
    "Copper",
    "Zinc",
    "Gallium",
    "Germanium",
    "Arsenic",
    "Selenium",
    "Bromine",
    "Krypton", 
    "Rubudium",
    "Strontium",
    "Yttrium",
    "Zirconium",
    "Niobium",
    "Molybdenum",
    "Technetium",
    "Ruthenium",
    "Rhodium",
    "Palladium",
    "Silver",
    "Cadmium",
    "Indium",
    "Tin",
    "Antimony",
    "Tellurium",
    "Iodine",
    "Xenon", 
    "Cesium",
    "Barium",
    "Lanthanum",
    "Cerium",
    "Praseodymium",
    "Neodymium",
    "Promethium",
    "Samarium",
    "Europium",
    "Gadolinium",
    "Terbium",
    "Dysprosium",
    "Holmium",
    "Erbium",
    "Thulium",
    "Ytterbium",
    "Lutetium",
    "Hafnium",
    "Tantalum",
    "Tungsten",
    "Rhenium",
    "Osmium",
    "Iridium",
    "Platinum",
    "Gold",
    "Mercury",
    "Thalium",
    "Lead",
    "Bismuth",
    "Polonium",
    "Astatine",
    "Radon",
    "Francium",
    "Radium",
    "Actinium",
    "Thorium",
    "Protactinium",
    "Uranium",
    "Neptunium",
    "Plutonium",
    "Americium",
    "Curium",
    "Berkelium",
    "Californium",
    "Ensteinium",
    "Fermium",
    "Mendelevium",
    "Nobelium",
    "Lawrencium",
    "Rutherfordium",
    "Dubnium",
    "Seaborgium",
    "Bohrium",
    "Hassium",
    "Meitnerium",
    "Darmstadtium",
    "Roentgenium",
    "Copernicium",
    "Nihonium",
    "Flerovium",
    "Moscovium",
    "Livermorium",
    "Tennessine",
    "Oganesson",
};
char at_symbols[118][3] = {
    "H", "He",
    "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
    "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu",
    "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I", "Xe",
    "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy",
    "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
    "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
    "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
    "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
    "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
double at_weight[118] = {
    1.00, 4.00,
    6.94, 9.01, 10.81, 12.01, 14.00, 15.99, 18.99, 20.18,
    22.99, 24.30, 26.98, 28.08, 30.97, 32.06, 35.45, 39.95,
    39.09, 40.07, 44.95, 47.86, 50.94, 51.99, 54.93, 55.84,
    58.93, 58.69, 63.54, 65.38, 69.72, 72.63, 74.92, 78.97, 79.90, 83.79,
    85.46, 87.62, 88.90, 91.22, 92.90, 95.95, 97.00, 101.07, 102.91, 106.42, 107.87,
    112.41, 114.82, 118.71, 121.76, 127.60, 126.90, 131.29,
    132.91, 137.33, 138.91, 140.12, 140.91, 144.24, 145.00, 150.36, 151.96, 157.25, 158.93,
    162.50, 164.93, 167.26, 168.93, 173.05, 174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22,
    195.08, 196.97, 200.59, 204.38, 207.20, 208.98, 209.00, 210.00, 222.00,
    223.00, 226.00, 227.00, 232.04, 231.04, 238.03, 237.00, 244.00, 243.00, 247.00, 247.00, 251.00,
    252.00, 257.00, 258.00, 259.00, 266.00, 267.00, 268.00, 269.00, 270.00, 269.00, 278.00, 281.00,
    282.00, 285.00, 286.00, 289.00, 290.00, 293.00, 294.00, 294.00};
char elec_config[118][30] = {
    "1", "2",
    "2,1", "2,2", "2,3", "2,4",
    "2,5", "2,6", "2,7", "2,8",
    "2,8,1", "2,8,2", "2,8,3",
    "2,8,4", "2,8,5", "2,8,6",
    "2,8,7", "2,8,8", "2,8,8,1",
    "2,8,8,2", "2,8,9,2", "2,8,10,2",
    "2,8,11,2", "2,8,13,1", "2,8,13,2",
    "2,8,14,2", "2,8,15,2", "2,8,16,2",
    "2,8,18,1", "2,8,18,2", "2,8,18,3",
    "2,8,18,4", "2,8,18,5", "2,8,18,6",
    "2,8,18,7", "2,8,18,8", "2,8,18,8,1",
    "2,8,18,8,2", "2,8,18,9,2", "2,8,18,10,2",
    "2,8,18,12,1", "2,8,18,13,1", "2,8,18,13,2",
    "2,8,18,15,1", "2,8,18,16,1", "2,8,18,18",
    "2,8,18,18,1", "2,8,18,18,2", "2,8,18,18,3",
    "2,8,18,18,4", "2,8,18,18,5", "2,8,18,18,6", "2,8,18,18,7",
    "2,8,18,18,8", "2,8,18,18,8,1", "2,8,18,18,8,2", "2,8,18,18,9,2",
    "2,8,18,19,9,2", "2,8,18,21,8,2", "2,8,18,22,8,2", "2,8,18,23,8,2",
    "2,8,18,23,8,2", "2,8,18,25,8,2", "2,8,18,25,9,2", "2,8,18,27,8,2",
    "2,8,18,28,8,2", "2,8,18,29,8,2", "2,8,18,30,8,2", "2,8,18,31,8,2",
    "2,8,18,32,8,2", "2,8,18,32,9,2", "2,8,18,32,10,2", "2,8,18,32,11,2",
    "2,8,18,32,12,2", "2,8,18,32,13,2", "2,8,18,32,14,2", "2,8,18,32,15,2",
    "2,8,18,32,17,1", "2,8,18,32,18,1", "2,8,18,32,18,2", "2,8,18,32,18,3",
    "2,8,18,32,18,4", "2,8,18,32,18,5", "2,8,18,32,18,6", "2,8,18,32,18,7",
    "2,8,18,32,18,8", "2,8,18,32,18,8,1", "2,8,18,32,18,8,2", "2,8,18,32,18,9,2",
    "2,8,18,32,18,10,2", "2,8,18,32,20,9,2", "2,8,18,32,21,9,2", "2,8,18,32,22,9,2",
    "2,8,18,32,24,8,2", "2,8,18,32,25,8,2", "2,8,18,32,25,9,2", "2,8,18,32,27,8,2",
    "2,8,18,32,28,8,2", "2,8,18,32,29,8,2", "2,8,18,32,30,8,2)", "2,8,18,32,31,8,2",
    "2,8,18,32,32,8,2", "2,8,18,32,32,8,3", "2,8,18,32,32,10,2", "2,8,18,32,32,11,2",
    "2,8,18,32,32,12,2", "2,8,18,32,32,13,2", "2,8,18,32,32,14,2", "2,8,18,32,32,15,2",
    "2,8,18,32,32,16,2", "2,8,18,32,32,17,2", "2,8,18,32,32,18,2", "2,8,18,32,32,18,3",
    "2,8,18,32,32,18,4", "2,8,18,32,32,18,5", "2,8,18,32,32,18,6", "2,8,18,32,32,18,7",
    "2,8,18,32,32,18,8"};
char year_of_discovery[118][10] = {
    "1766", "1895",
    "1817", "1797", "1808",
    "Ancient", "1772",
    "1774", "1896", "1898",
    "1807", "1755", "1825", "1824", "1669", "Ancient",
    "1774", "1894",
    "1807", "1808", "1879", "1791", "1801", "1798", "1774",
    "Ancient",
    "1739", "1751", "Ancient",
    "20 BC", "1875", "1886", "1250", "1817", "1826", "1898",
    "1861", "1790", "1794", "1789", "1801",
    "1781", "1937", "1844", "1803",
    "1803", "Ancient", "1817", "1863", "Ancient", "Ancient", "1783", "1811", "1898",
    "1860", "1808",
    "1839", "1803", "1885",
    "1885", "1945", "1879", "1901", "1880",
    "1843", "1896", "1878", "1843", "1879", "1878", "1907", "1923", "1802", "1783",
    "1925", "1803", "1803", "1750",
    "Ancient", "Ancient", "1861", "Ancient",
    "1500", "1898", "1940", "1900",
    "1939", "1898", "1899", "1829", "1913",
    "1789", "1940", "1940", "1944", "1944",
    "1949", "1950", "1952", "1953", "1955",
    "1963", "1965", "1964", "1968", "1974",
    "1981", "1984",
    "1982", "1994", "1994", "1996", "2004", "1999",
    "2010", "2000", "2010", "2006"};
char atomic_state[118][10] = {
    "Gas",
    "Gas",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Gas",
    "Gas",
    "Gas",
    "Gas",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Gas",
    "Gas",
    "Gas",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Gas",
    "Gas",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Gas",
    "Solid",
    "Solid ",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Liquid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Gas",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Solid",
    "Gas",
};
char recent_use[118][1000] = {
    "Researchers at the KU Leuven university, Belgium, have developed a solar hydrogen panel that is able to produce 250l of H2 / d directly from sunlight and water vapor utilizing phytocatalytic water splitting and they are reporting a conversion efficiency of 15%%. According to IEEE Spectrum this is a gain of +14,900% from the efficiency figure 10 years back (0.1%%)",
    "Labs all over the U.S. use liquid helium to cool instruments that will only work at super-low temperatures. The devices that measure very small magnetic fields for brain cell research need liquid helium", //2
    "the single most important use of lithium in the modern world is in rechargeable lithium-ion batteries. With consumers demanding longer-lasting, lighter, smaller, more powerful batteries for personal devices and industrial equipment, lithium was found to be the ideal element that could satisfy all these multiple needs.",
    "Beryllium is used in gears and cogs particularly in the aviation industry. Beryllium is a silvery-white metal. It is relatively soft and has a low density. Beryllium is used in alloys with copper or nickel to make gyroscopes, springs, electrical contacts, spot-welding electrodes and non-sparking tools.",
    "Hexagonal boron nitride (h-BN) is the iron man of 2D materials, so resistant to cracking that it defies a century-old theoretical description engineers still use to measure toughness.",
    "There has been significant practical interest in the conductivity of CNTs. CNTs with particular combinations of M and N (structural parameters indicating how much the nanotube is twisted) can be highly conducting, and hence can be considered as metallic. Their conductivity has been proved to be a function of their diameter as well as their chirality (degree of twist). CNTs can be either semi-conducting or metallic in their electrical behavior.",
    "World-changing technology enables crops to take nitrogen from the air:A major new technology enables all of the world's crops to take nitrogen from the air rather than expensive and environmentally damaging fertilizers. Nitrogen fixation, the process by which nitrogen is converted to ammonia, is vital for plants to survive and grow. However, only a very small number of plants, most notably legumes (such as peas, beans and lentils) have the ability to fix nitrogen from the atmosphere with the help of nitrogen fixing bacteria. The vast majority of plants have to obtain nitrogen from the soil, and for most crops currently being grown across the world, this also means a reliance on synthetic nitrogen fertilizer.",
    "Hyperbaric (high-pressure) medicine uses special oxygen chambers to increase the partial pressure of O2 around the patient and, when needed, the medical staff. Carbon monoxide poisoning, gas gangrene, and decompression sickness (the ‘bends’) are sometimes treated using these devices. Increased O2concentration in the lungs helps to displace carbon monoxide from the heme group of hemoglobin. Oxygen gas is poisonous to the anaerobic bacteria that cause gas gangrene, so increasing its partial pressure helps kill them.",
    "Fluorine is required for the preparation of uranium(VI) fluoride and subsequent separation of the 235 and 238 uranium isotopes by gaseous diffusion.  The main ore of uranium contains uranium oxide, U2O3.  It is treated with hydrofluoric acid to form uranium(IV) fluoride, UF4.  This is purified and then converted to uranium(VI) fluoride, UF6, with fluorine.",
    "The largest use of neon is in making the ubiquitous ‘neon signs’ for advertising. In a vacuum discharge tube neon glows a reddish orange colour. Only the red signs actually contain pure neon. Others contain different gases to give different colours.Neon is also used to make high-voltage indicators and switching gear, lightning arresters, diving equipment and lasers.Liquid neon is an important cryogenic refrigerant. It has over 40 times more refrigerating capacity per unit volume than liquid helium, and more than 3 times that of liquid hydrogen.", //8
    "In a recent study published in Angewandte Chemie International Edition, the team revealed that they found an energy-efficient method to produce a novel carbon-based material for sodium-ion batteries with very high sodium storage capacity.The study focused on the synthesis of hard carbon, a highly porous material that serves as the negative electrode of rechargeable batteries, through the use of magnesium oxide (MgO) as an inorganic template of nano-sized pores inside hard carbon.",
    "By far the greatest use of magnesium is as an alloying element in aluminum. In amounts ranging from less than 1 percent to approximately 10 percent, magnesium enhances the mechanical properties as well as the corrosion resistance of aluminum alloys. Similarly, pure aluminum is used as an alloying element in many magnesium-based alloys.",
    "Aluminium has been an integral component of the journey of transformation for the construction industry. From skyscrapers to green buildings, aluminium is the first choice for architects and builders across the globe. Due to its sustainable nature and property of being recycled and reused, aluminium has now become a preferred material for builders who are looking to implement new technologies in the building and construction sector. Aluminium and its various forms have vast and diverse applications in the construction industry.",
    "Crystalline silicon (c-Si) technologies have dominated the market for the last 30 years. Amorphous silicon (a-Si) technology has been the choice most widely used for consumer applications due to its low manufacturing cost, while c-Si technologies have been used mainly in both stand-alone and on-grid system applications.",
    "Ion exchange technologies are well established and used in many contexts, including desalination and the deionization of water (Awual and Jyo, 2011). The principle of ion exchange also can be applied to the removal of Phosphorous from wastewater and some suggest the technology may be particularly suitable for use at decentralized locations (Zhao and Sengupta, 1998). Whilst not as widely studied or applied as other physico-chemical Phosphorous removal methods, the highly selective nature of some exchange media means that their consideration is warranted.",
    "Sulfur (specifically octasulfur, S8) is used in pharmaceutical skin preparations for the treatment of acne and other conditions. It acts as a keratolytic agent and also kills bacteria, fungi, scabies mites, and other parasites. Precipitated sulfur and colloidal sulfur are used, in form of lotions, creams, powders, soaps, and bath additives, for the treatment of acne vulgaris, acne rosacea, and seborrhoeic dermatitis.",
    "Chlorine even plays an important role in harnessing solar energy—purifying the silicon found in grains of sand and helping transform them into solar panel chips. In so many ways, chlorine is part of the bedrock of sustainable development efforts and other central tenets of modern environmental protection.",
    "Liquid argon is used as the target for neutrino experiments and direct dark matter searches. The interaction between the hypothetical WIMPs and an argon nucleus produces scintillation light that is detected by photomultiplier tubes. Two-phase detectors containing argon gas are used to detect the ionized electrons produced during the WIMP–nucleus scattering.", //8
    "Sodium-potassium alloy (NaK) is used to a limited extent as a heat-transfer coolant in some fast-breeder nuclear reactors and experimentally in gas-turbine power plants. The alloy is also used as a catalyst or reducing agent in organic synthesis.", "Calcium compounds are widely used. There are vast deposits of limestone (calcium carbonate) used directly as a building stone and indirectly for cement. When limestone is heated in kilns it gives off carbon dioxide gas leaving behind quicklime (calcium oxide). This reacts vigorously with water to give slaked lime (calcium hydroxide). Slaked lime is used to make cement, as a soil conditioner and in water treatment to reduce acidity, and in the chemicals industry. It is also used in steel making to remove impurities from the molten iron ore. When mixed with sand, slaked lime takes up carbon dioxide from the air and hardens as lime plaster.",
    "Theoretical investigations indicated that scandium carbide (Sc2C) MXenes have many superior properties, although they are not yet actually synthesized. Sc2C MXene with bare surface was predicted to possess a high gravimetric hydrogen storage capacity of 9%", "Titanium metal is used as an alloying agent with metals including aluminum, iron, molybdenum and manganese. Alloys of titanium are mainly used in aerospace, aircraft and engines where strong, lightweight, temperature-resistant materials are needed.",
    "Vanadium is an important component of mixed metal oxide catalysts used in the oxidation of propane and propylene to acrolein, acrylic acid or the ammoxidation of propylene to acrylonitrile.In service, the oxidation state of vanadium changes dynamically and reversibly with the oxygen and the steam content of the reacting feed mixture.",
    "Various chromium salts processed from chromite are the main raw materials in the chemical industry. Chromium salt is one of the main varieties of inorganic salts. It is mainly used in electroplating, tanning, printing, and dyeing, medicine, fuel, catalysts, oxidants, matches, and metal corrosion inhibitors.",
    "Magnesium is the second most important intracellular cation and is involved in a variety of metabolic processes including glucose metabolism, ion channel translocation, stimulus-contraction coupling, stimulus secretion coupling, peptide hormone receptor signal transduction",
    "About 98% of iron ore is used to make steel – one of the greatest inventions and most useful materials ever created. While the other uses for iron ore and iron are only a very small amount of the consumption, they provide excellent examples of the ingenuity and the multitude of uses that humans can create from natural resources. Powdered iron: used in metallurgy products, magnets, high-frequency cores, auto parts, catalyst. Radioactive iron (iron 59): in medicine, tracer element in biochemical and metallurgical research. Iron blue: in paints, printing inks, plastics, cosmetics ",
    " cobalt use is as an essential element in the metabolism of humans and animals — those who cannot retain cobalt naturally have to be treated with B12 vitamin therapy, which contains cobalt. Cobalt-60 is also used for cancer treatment via radiotherapy, and cobalt is applied in soil dressings in cobalt-deficient soil to prevent “wasting disease” in grazing animals"
    "Nickel is used in many specific and recognizable industrial and consumer products, including stainless steel, alnico magnets, coinage, rechargeable batteries, electric guitar strings, microphone capsules, plating on plumbing fixtures, and special alloys such as permalloy, elinvar, and invar. It is used for plating and as a green tint in glass. Nickel is preeminently an alloy metal, and its chief use is in nickel steels and nickel cast irons, in which it typically increases the tensile strength, toughness, and elastic limit.",
    "Nickel is used in many specific and recognizable industrial and consumer products, including stainless steel, alnico magnets, coinage, rechargeable batteries, electric guitar strings, microphone capsules, plating on plumbing fixtures,[73] and special alloys such as permalloy, elinvar, and invar. It is used for plating and as a green tint in glass. Nickel is preeminently an alloy metal, and its chief use is in nickel steels and nickel cast irons, in which it typically increases the tensile strength, toughness, and elastic limit.", " Cu",
    "Zinc is more reactive than iron or steel and thus will attract almost all local oxidation until it completely corrodes away. A protective surface layer of oxide and carbonate forms as the zinc corrodes. This protection lasts even after the zinc layer is scratched but degrades through time as the zinc corrodes away. The zinc is applied electrochemically or as molten zinc by hot-dip galvanizing or spraying. Galvanization is used on chain-link fencing, guard rails, suspension bridges, lightposts, metal roofs, heat exchangers, and car bodies.", "Gallium arsenide and gallium nitride can also be found in a variety of optoelectronic devices which had a market share of $15.3 billion in 2015 and $18.5 billion in 2016. Aluminium gallium arsenide (AlGaAs) is used in high-power infrared laser diodes. The semiconductors gallium nitride and indium gallium nitride are used in blue and violet optoelectronic devices, mostly laser diodes and light-emitting diodes. For example, gallium nitride 405 nm diode lasers are used as a violet light source for higher-density Blu-ray Disc compact data disc drives",
    "Because germanium and gallium arsenide have very similar lattice constants, germanium substrates can be used to make gallium arsenide solar cells.[76] The Mars Exploration Rovers and several satellites use triple junction gallium arsenide on germanium cells",
    "After World War I, the United States built a stockpile of 20,000 tons of weaponized lewisite (ClCH=CHAsCl2), an organoarsenic vesicant (blister agent) and lung irritant. The stockpile was neutralized with bleach and dumped into the Gulf of Mexico in the 1950s.", "Amorphous selenium (α-Se) thin films have found application as photoconductors in flat panel x-ray detectors.These detectors use amorphous selenium to capture and convert incident x-ray photons directly into electric charge.", "Brominated flame retardants represent a commodity of growing importance, and make up the largest commercial use of bromine. When the brominated material burns, the flame retardant produces hydrobromic acid which interferes in the radical chain reaction of the oxidation reaction of the fire. The mechanism is that the highly reactive hydrogen radicals, oxygen radicals, and hydroxy radicals react with hydrobromic acid to form less reactive bromine radicals ",
    "Krypton's multiple emission lines make ionized krypton gas discharges appear whitish, which in turn makes krypton-based bulbs useful in photography as a white light source. Krypton is used in some photographic flashes for high speed photography", //18
    "Rb", "Strontium is the active ingredient in Metastron,[71] a radiopharmaceutical used for bone pain secondary to metastatic bone cancer. The strontium is processed like calcium by the body, preferentially incorporating it into bone at sites of increased osteogenesis. This localization focuses the radiation exposure on the cancerous lesion.", "The actual superconducting material is often written as YBa2Cu3O7–d, where d must be less than 0.7 for superconductivity. The reason for this is still not clear, but it is known that the vacancies occur only in certain places in the crystal, the copper oxide planes, and chains, giving rise to a peculiar oxidation state of the copper atoms, which somehow leads to the superconducting behavior.",
    "Cladding for nuclear reactor fuels consumes about 1% of the zirconium supply,[19] mainly in the form of zircaloys. The desired properties of these alloys are a low neutron-capture cross-section and resistance to corrosion under normal service conditions. Efficient methods for removing the hafnium impurities were developed to serve this purpose.", "Quantities of niobium are used in nickel-, cobalt-, and iron-based superalloys in proportions as great as 6.5%for such applications as jet engine components, gas turbines, rocket subassemblies, turbo charger systems, heat resisting, and combustion equipment. Niobium precipitates a hardening γ''-phase within the grain structure of the superalloy.",
    "Elemental molybdenum is used in NO, NO2, NOx analyzers in power plants for pollution controls. At 350 °C (662 °F), the element acts as a catalyst for NO2/NOx to form NO molecules for detection by infrared light.",
    "Technetium-99m ("
    " indicates that this is a metastable nuclear isomer) is used in radioactive isotope medical tests. For example, Technetium-99m is a radioactive tracer that medical imaging equipment tracks in the human body.",
    "Relatively recently, ruthenium has been suggested as a material that could beneficially replace other metals and silicides in microelectronics components. Ruthenium tetroxide (RuO4) is highly volatile, as is ruthenium trioxide (RuO3).By oxidizing ruthenium (for example with an oxygen plasma) into the volatile oxides, ruthenium can be easily patterned.",
    "Rhodium finds use in jewelry and for decorations. It is electroplated on white gold and platinum to give it a reflective white surface at time of sale, after which the thin layer wears away with use. This is known as rhodium flashing in the jewelry business.",
    "Hydrogen easily diffuses through heated palladium, and membrane reactors with Pd membranes are used in the production of high purity hydrogen. Palladium is used in palladium-hydrogen electrodes in electrochemical studies. Palladium(II) chloride readily catalyzes carbon monoxide gas to carbon dioxide and is useful in carbon monoxide detectors.", "Nanosilver particles, between 10 and 100 nanometres in size, are used in many applications. They are used in conductive inks for printed electronics, and have a much lower melting point than larger silver particles of micrometre size. They are also used medicinally in antibacterials and antifungals in much the same way as larger silver particles.", "Cadmium selenide quantum dots emit bright luminescence under UV excitation (He-Cd laser, for example). The color of this luminescence can be green, yellow or red depending on the particle size. Colloidal solutions of those particles are used for imaging of biological tissues and solutions with a fluorescence microscope.", "Indium(III) oxide and indium tin oxide (ITO) are used as a transparent conductive coating on glass substrates in electroluminescent panels. Indium tin oxide is used as a light filter in low-pressure sodium-vapor lamps. The infrared radiation is reflected back into the lamp, which increases the temperature within the tube and improves the performance of the lamp.",
    "Punched tin-plated steel, also called pierced tin, is an artisan technique originating in central Europe for creating housewares that are both functional and decorative. Decorative piercing designs exist in a wide variety, based on local tradition and the artisan's personal creations. Punched tin lanterns are the most common application of this artisan technique. ", "Not Known", "Not Known",
    "The spectra of the iodine molecule, I2, consists of (not exclusively) tens of thousands of sharp spectral lines in the wavelength range 500–700 nm. It is therefore a commonly used wavelength reference (secondary standard). By measuring with a spectroscopic Doppler-free technique while focusing on one of these lines, the hyperfine structure of the iodine molecule reveals itself.", "Continuous, short-arc, high pressure xenon arc lamps have a color temperature closely approximating noon sunlight and are used in solar simulators. That is, the chromaticity of these lamps closely approximates a heated black body radiator at the temperature of the Sun. First introduced in the 1940s, these lamps replaced the shorter-lived carbon arc lamps in movie projectors", //18
    "The most common use for caesium compounds is as a drilling fluid. They are also used to make special optical glass, as a catalyst promoter, in vacuum tubes and in radiation monitoring equipment. One of its most important uses is in the 'caesium clock' .", "Barium compounds are also used to make paint, bricks, tiles, glass, and rubber.", "Hydrogen sponge alloys can contain lanthanum. These alloys are capable of storing up to 400 times their own volume of hydrogen gas in a reversible adsorption process. Heat energy is released every time they do so; therefore these alloys have possibilities in energy conservation systems.",
    "Cerium salts, such as the sulfides Ce2S3 and Ce3S4, were considered during the Manhattan Project as advanced refractory materials for the construction of crucibles which could withstand the high temperatures and strongly reducing conditions when casting plutonium metal.",
    "Praseodymium alloyed with nickel (PrNi5) has such a strong magnetocaloric effect that it has allowed scientists to approach within one thousandth of a degree of absolute zero.",
    "Probably because of similarities to Ca2+, Nd3+ has been reportedto promote plant growth. Rare-earth-element compounds are frequently used in China as fertilizer.", "In atomic batteries, the beta particles emitted by promethium-147 are converted into electric current by sandwiching a small promethium source between two semiconductor plates. These batteries have a useful lifetime of about five years.", "important application of samarium and its compounds is as catalyst and chemical reagent. Samarium catalysts assist decomposition of plastics, dechlorination of pollutants such as polychlorinated biphenyls (PCBs), as well as the dehydration and dehydrogenation of ethanol", "Not known",
    "Gadolinium as a phosphor is also used in other imaging. In X-ray systems gadolinium is contained in the phosphor layer, suspended in a polymer matrix at the detector. Terbium-doped gadolinium oxysulfide (Gd2O2S:Tb) at the phosphor layer converts the X-rays released from the source into light. This material emits green light at 540 nm due to the presence of Tb3+, which is very useful for enhancing the imaging quality. The energy conversion of Gd is up to 20%, which means that 1/5 of the X-ray energy striking the phosphor layer can be converted into visible photons.",
    "Terbium is also used in alloys and in the production of electronic devices. As a component of Terfenol-D, terbium is used in actuators, in naval sonar systems, sensors, in the SoundBug device (its first commercial application), and other magnetomechanical devices. Terfenol-D is a terbium alloy that expands or contracts in the presence of a magnetic field. It has the highest magnetostriction of any alloy.", "Dysprosium is used in dosimeters for measuring ionizing radiation. Crystals of calcium sulfate or calcium fluoride are doped with dysprosium. When these crystals are exposed to radiation, the dysprosium atoms become excited and luminescent. The luminescence can be measured to determine the degree of exposure to which the dosimeter has been subjected", "It is commercially extracted by ion exchange from monazite sand (0.05% holmium), but is still difficult to separate from other rare earths. The element has been isolated through the reduction of its anhydrous chloride or fluoride with metallic calcium.", "A large variety of medical applications (i.e. dermatology, dentistry) utilize erbium ion's 2940 nm emission (see Er:YAG laser), which is highly absorbed in water (absorption coefficient about 12000/cm).", "Despite its high cost, portable X-ray devices use thulium that has been bombarded with neutrons in a nuclear reactor to produce the isotope Thulium-170, having a half-life of 128.6 days and five major emission lines of comparable intensity (at 7.4, 51.354, 52.389, 59.4 and 84.253 keV).", "The Yb3+ ion is used as a doping material in active laser media, specifically in solid state lasers and double clad fiber lasers. Ytterbium lasers are highly efficient, have long lifetimes and can generate short pulses; ytterbium can also easily be incorporated into the material used to make the laser.", "Not known", "Hafnium is readily substituted into the zircon crystal lattice, and is therefore very resistant to hafnium mobility and contamination. Zircon also has an extremely low Lu/Hf ratio, making any correction for initial lutetium minimal. Although the Lu/Hf system can be used to calculate a model age",
    " Tantalum electrolytic capacitors exploit the tendency of tantalum to form a protective oxide surface layer, using tantalum powder, pressed into a pellet shape, as one plate of the capacitor, the oxide as the dielectric, and an electrolytic solution or conductive solid as the other plate",
    "Current uses are as electrodes, heating elements and field emitters, and as filaments in light bulbs and cathode ray tubes. Tungsten is commonly used in heavy metal alloys such as high speed steel, from which cutting tools are manufactured. It is also used in the so-called 'superalloys' to form wear-resistant coatings.", "Re",
    "Because of the volatility and extreme toxicity of its oxide, osmium is rarely used in its pure state, but is instead often alloyed with other metals for high-wear applications. Osmium alloys such as osmiridium are very hard and, along with other platinum-group metals, are used in the tips of fountain pens, instrument pivots, and electrical contacts, as they can resist wear from frequent operation. They were also used for the tips of phonograph styli during the late 78 rpm and early LP and 45 record era, circa 1945 to 1955.",
    "An alloy of 90% platinum and 10% iridium was used in 1889 to construct the International Prototype Metre and kilogram mass, kept by the International Bureau of Weights and Measures near Paris.", "As platinum is a catalyst in the manufacture of the silicone rubber and gel components of several types of medical implants (breast implants, joint replacement prosthetics, artificial lumbar discs, vascular access ports, etc.), the possibility that platinum could enter the body and cause adverse effects has merited study. The Food and Drug Administration and other institutions have reviewed the issue and found no evidence to suggest toxicity in vivo.", "Wealth protection and a financial exchange. One of the oldest uses of gold is for coins, and other financial assets and space exploration.",
    "Although many liquids could be used in pressure measuring devices, mercury is used because its high density requires less space. It is also a good conductor of electricity, so it is a useful component of electrical switches. Mercury is also used in dental fillings, paints, soaps, batteries, and fluorescent lighting.", "Acousto-optic laser equipment, HIgh-temperature superconductors, Detection of gamma radiation, Infrared light-sensitive photocells and Low-temperature thermometers",
    "Lead is still widely used for car batteries, pigments, ammunition, cable sheathing, weights for lifting, weight belts for diving, lead crystal glass, radiation protection and in some solders. It is often used to store corrosive liquids.", "The density difference between lead and bismuthis small enough that for many ballistics and weighting applications, bismuth can substitute for lead. For example, it can replace lead as a dense material in fishing sinkers. It has been used as a replacement for lead in shot, bullets and less-lethal riot gun ammunition. ", "Because of intense alpha radiation, a one-gram sample of 210Po will spontaneously heat up to above 500 °C (932 °F) generating about 140 watts of power. Therefore, 210Po is used as an atomic heat source to power radioisotope thermoelectric generators via thermoelectric materials.", "At", "Radon(Rn)is chemically inert, but radioactive. Radon decays into radioactive polonium and alpha particles. This emitted radiation made radon useful in cancer therapy. Radon was used in some hospitals to treat tumours by sealing the gas in minute tubes, and implanting these into the tumour, treating the disease in situ.", //32
    "Francium's ability to be synthesized, trapped, and cooled, along with its relatively simple atomic structure, has made it the subject of specialized spectroscopy experiments. These experiments have led to more specific information regarding energy levels and the coupling constants between subatomic particles.Studies on the light emitted by laser-trapped francium-210 ions have provided accurate data on transitions between atomic energy levels which are fairly similar to those predicted by quantum theory.",
    "Radium was formerly used in self-luminous paints for watches, nuclear panels, aircraft switches, clocks, and instrument dials. Earlier, Ra was used as an additive in a product such as toothpaste, hair cream, and even food items.", "Ac", "As thorium is radioactive, its uses mainly lie in nuclear fuel applications, It is helpful in radiometric dating and Used in manufacturing of lenses for cameras and scientific instruments", "Not Known", "Uranium is also used by the military to power nuclear submarines and in nuclear weapons. Depleted uranium is uranium that has much less uranium-235 than natural uranium. It is considerably less radioactive than natural uranium. It is a dense metal that can be used as ballast for ships and counterweights for aircraft.", "Neptunium is fissionable, and could theoretically be used as fuel in a fast neutron reactor or a nuclear weapon, with a critical mass of around 60 kilograms As of 2009, the world production of neptunium-237 by commercial power reactors was over 1000 critical masses a year, but to extract the isotope from irradiated fuel elements would be a major industrial undertaking.",
    "Different uses have been found for plutonium. Plutonium-238 has been used to power batteries for some heart pacemakers, as well as provide a long-lived heat source to power NASA space missions. Like uranium, plutonium can also be used to fuel nuclear power plants.",
    "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored",
    "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored", "Very limited knowledge about the element, Yet to be explored" //32
};
char oxidation_state[118][100] = {
    "-1,+1",
    "No Oxidation State Stable", 
    "+1",
    "0,+1,+2",
    "-5,-1,0,+1,+2,+3",
    "-4,-3,-2,-1,0,+1,+2,+3,+4",
    "-3,-2,-1,+1,+2,+3,+4,+5",
    "-2,-1,0,+1,+2",
    "-1,0",
    "No Oxidation State Stable", 
    "+1",
    "0,+1,+2",
    "-2,-1,+1,+2,+3",
    "-4,-2,-1,0,+1,+2,+3,+4",
    "-3,-2,-1,0,+1,+2,+3,+4,+5",
    "-2,-1,0,+1,+2,+3,+4,+6",
    "-1,+1,+2,+3,+4,+5,+6,+7",
    "0", 
    "+1",
    "0,+1,+2",
    "0,+1,+2,+3",
    "-2,-1,0,+1,+2,+3,+4",
    "-3,-1,0,+1,+2,+3,+4,+5",
    "-4,-1,0,+1,+2,+3,+4,+5,+6",
    "-3,-2,-1,0,+1,+2,+3,+4,+5,+6,+7",
    "-4,-2,-1,0,+1,+2,+3,+4,+5,+6,+7",
    "-3,-1,0,+1,+2,+3,+4,+5",
    "-2,-1,0,+1,+2,+3,+4",
    "-2,0,+1,+2,+3,+4",
    "-2,0,+1,+2,+3,+4",
    "-5,-4,-2,-1,+1,+2,+3",
    "-4,-2,-1,0,+1,+2,+3,+4",
    "-3,-2,-1,0,+1,+2,+3,+4,+5",
    "-2,-1,+1,+2,+3,+4,+5,+6",
    "-1,+1,+3,+4,+5,+7",
    "0,+1,+2", 
    "+1",
    "0,+1,+2",
    "0,+1,+2,+3",
    "-2,0,+1,+2,+3,+4",
    "-3,-1,0,+1,+2,+3,+4,+5",
    "-4,-2,-1,0,+1,+2,+3,+4,+5,+6",
    "-3,-2,-1,0,+1,+2,+3,+4,+5,+6,+7",
    "-4,-2,0,+1,+2,+3,+4,+5,+6,+7,+8",
    "-3,-1,0,+1,+2,+3,+4,+5,+6",
    "0,+1,+2,+3,+4",
    "-2,-1,+1,+2,+3",
    "-2,+1,+2",
    "-5,-2,-1,+1,+2,+3",
    "-4,-3,-2,-1,0,+1,+2,+3,+4",
    "-3,-2,-1,0,+1,+2,+3,+4,+5",
    "-2,-1,+1,+2,+3,+4,+5",
    "-1,+1,+3,+4,+5,+6,+7",
    "0,+1,+2,+4,+6,+8", 
    "+1",
    "0,+1,+2",
    "0,+1,+2,+3",
    "+2,+3,+4",
    "0,+1,+2,+3,+4,+5",
    "0,+2,+3,+4",
    "+2,+3",
    "0,+2,+3",
    "+2,+3",
    "0,+2,+3",
    "0,+1,+2,+3",
    "0,+2,+3,+4",
    "0,+2,+3",
    "0,+2,+3",
    "0,+2,+3",
    "0,+2,+3",
    "0,+2,+3",
    "-2,0,+1,+2,+3,+4",
    "-3,-1,0,+1,+2,+3,+4",
    "-4,-2,-1,0,+1,+2,+3,+4,+5,+6",
    "-3,-1,0,+1,+2,+3,+4,+5,+6,+7",
    "-4,-2,-1,0,+1,+2,+3,+4,+5,+6,+7,+8",
    "-3,-1,0,+1,+2,+3,+4,+5,+6,+7,+8,+9",
    "-3,-2,-1,0,+1,+2,+3,+4,+5,+6",
    "-3,-1,0,+1,+2,+3,+5",
    "-2,+1+2",
    "-5,-2,-1,0,+1,+2,+3",
    "-4,-2,-1,+1,+2,+3,+4",
    "-3,-2,-1,+1,+2,+3,+4,+5",
    "-2,+2,+4,+5,+6",
    "-1,+1,+3,+5,+7",
    "+2,+6", 
    "+1",
    "+2",
    "+2,+3",
    "+1,+2,+3,+4",
    "+3,+4,+5",
    "+1,+2,+3,+4,+5,+6",
    "+2,+3,+4,+5,+6,+7",
    "+2,+3,+4,+5,+6,+7,+8",
    "+2,+3,+4,+5,+6,+7",
    "+3,+4,+5,+6",
    "+2,+3,+4,+5",
    "+2,+3,+4,+5",
    "+2,+3,+4",
    "+2,+3",
    "+2,+3",
    "+2,+3",
    "+3",
    "+4",
    "+5",
    "+6",
    "+7",
    "+8",
    "No known oxidation state",
    "No known oxidation state",
    "No known oxidation state",
    "+2",
    "No known oxidation state",
    "No known oxidation state",
    "No known oxidation state",
    "No known oxidation state",
    "No known oxidation state",
    "No known oxidation state",
};
int main(void)
{
    int i = 999, choice;
    do
    {
        choice = get_choice();
        char ch1, ch2, ch3, ch4, ch5;
        switch (choice)
        {
        case 1:
            i = atomic_number();
            break;
        case 2:
            i = atomic_symbol();
            break;
        case 3:
            i = atomic_name();
            // printf("%d",i);
            break;
        case 4:
            i = atomic_weight();
            break;
        case 5:
            return (0);

        default:
            printf("\t\t\t\tOops!\t\t\t\t");
            printf("Enter a valid choice");
        }
        if (i == -1)
        {

            printf("\t\t\t\t OOPS \n\t\t\t");
            printf("\t\t\t\t Make a right choice \n\t\t\t");
        }
        else if (i == 999)
        {
            continue;
        }
        else
        {
            ch1 = atomic_block(i);
            ch2 = atomic_property(i);
            ch3 = atomic_period(i);
            ch4 = atomic_group(i);
            ch5 = atomic_class(i);
            display(i, ch1, ch2, ch3, ch4, ch5);
        }
        i = 999;
    } while (choice != 6);
    fflush(stdin);

    return (0);
}

int get_choice(void)
{
    int input;
    printf("\t\t\t\t--------------------------WELCOME---------------- \t\t\t\t\n");
    printf("\t\t\t\t******************************************************************\n");
    printf("\t\t\t\tEnter you choice below\n");
    printf("\t\t\t\t1.Search by Atomic No.\n");
    printf("\t\t\t\t2.Search by Atomic Symbol\n");
    printf("\t\t\t\t3.Search by Atomic Name\n");
    printf("\t\t\t\t4.Search by Atomic Weight\n");
    printf("\t\t\t\t5.To exit the programme\n");
    printf("\t\t\t\tEnter your choice:\n\t\t\t\t");
    scanf("%d", &input);
    return input;
}
int atomic_number(void)
{
    int atomicno;
    printf("\t\t\t\tEnter the atomic no. of the element:");
    scanf("%d", &atomicno);
    atomicno--;
    if (atomicno >= 0 && atomicno < 118)
    {
        return atomicno;
    }
    else
    {
        return -1;
    }
}
int atomic_name(void)
{
    char name[20];
    int i, flag = 0;
    printf("\t\t\t\tEnter the name of the element\nWarning:\n Please enter the first letter capital and make sure the spelling is correct:\n");
    scanf("%s", name);
    for (i = 0; i < 118; i++)
    {
        if (strcmp(name, atoms[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int atomic_symbol(void)
{
    char symbol[3];
    int i, flag = 0;
    printf("\t\t\t\tEnter the atomic symbol of the element:\n");
    scanf("%s", symbol);
    for (i = 0; i < 118; i++)
    {
        if (strcmp(symbol, at_symbols[i]) == 0)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int atomic_weight(void)
{
    double atomic_mass;
    int i, flag = 0;
    printf("\t\t\t\tEnter the atomic mass of the element\n");
    scanf("%lf", &atomic_mass);
    for (i = 0; i < 118; i++)
    {
        if (at_weight[i] == atomic_mass)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int electronic_configuration()
{
    int i, flag = 0;
    char electronic_config[30];
    printf("\t\t\t\tEnter the electronic configuration in terms of shell\n");
    scanf("%s", electronic_config);
    for (i = 0; i < 118; i++)
    {
        if (strcmp(electronic_config, elec_config[i]) == 0)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
char atomic_block(int i)
{
    char ch = ' ';
    int n = i + 1;
    if (n == 1 || n == 3 || n == 11 || n == 19 || n == 37 || n == 35 || n == 87 || n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        ch = 's';
    }
    else if ((n >= 5 && n <= 10) || (n >= 13 && n <= 18) || (n >= 31 && n <= 36) || (n >= 49 && n <= 54) || (n >= 81 && n <= 86) || (n >= 113 && n <= 118))
    {
        ch = 'p';
    }
    else if (21 <= n <= 30 || 39 <= n <= 48 || 71 <= n <= 80 || 103 <= n <= 112)
    {
        ch = 'd';
    }
    else if (57 <= n <= 70 || 89 <= n <= 102)
    {
        ch = 'f';
    }

    // else
    // {
    //     printf("This element is yet to be discovered :p");
    // }
    return ch;
}
char atomic_property(int i)
{
    int n = i + 1;
    char ch = ' ';
    if (n == 1 || n == 2 || (n >= 6 && n <= 10) || (n >= 15 && n <= 18) || (n >= 34 && n <= 36) || n == 53 || n == 54 || n == 86 || n == 117 || n == 118)
    {
        ch = 'n';
    }
    else if (n == 3 || n == 4 || (n >= 11 && n <= 13) || (n >= 19 && n <= 31) || (n >= 37 && n <= 50) || (n >= 55 && n <= 84) || (n >= 87 && n <= 116))
    {
        ch = 'm';
    }
    else
    {
        ch = 'x';
    }
    return ch;
}
int atomic_period(int i)
{
    int n = i + 1;
    int period;
    if (n == 1 || n == 2)
    {
        period = 1;
    }
    else if (n >= 3 && n <= 10)
    {
        period = 2;
    }
    else if (n >= 11 && n <= 18)
    {
        period = 3;
    }
    else if (n >= 19 && n <= 36)
    {
        period = 4;
    }
    else if (n >= 37 && n <= 54)
    {
        period = 5;
    }
    else if (n >= 55 && n <= 86)
    {
        period = 6;
    }
    else if (n >= 87 && n <= 118)
    {
        period = 7;
    }
    return period;
}
int atomic_group(int i)
{
    int group;
    char str[30];
    int n = i + 1;
    if (n == 1 || n == 3 || n == 11 || n == 19 || n == 37 || n == 55 || n == 87)
    {
        group = 1;
    }
    else if (n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        group = 2;
    }
    else if (n == 21 || n == 39 || (n >= 57 && n <= 71) || (n >= 89 && n <= 103))
    {
        group = 3;
    }
    else if (n == 22 || n == 40 || n == 72 || n == 104)
    {
        group = 4;
    }
    else if (n == 23 || n == 41 || n == 73 || n == 105)
    {
        group = 5;
    }
    else if (n == 24 || n == 42 || n == 74 || n == 106)
    {
        group = 6;
    }
    else if (n == 25 || n == 43 || n == 75 || n == 107)
    {
        group = 7;
    }
    else if (n == 26 || n == 44 || n == 76 || n == 108)
    {
        group = 8;
    }
    else if (n == 27 || n == 45 || n == 77 || n == 109)
    {
        group = 9;
    }
    else if (n == 28 || n == 46 || n == 78 || n == 110)
    {
        group = 10;
    }
    else if (n == 29 || n == 47 || n == 79 || n == 111)
    {
        group = 11;
    }
    else if (n == 30 || n == 48 || n == 80 || n == 112)
    {
        group = 12;
    }
    else if (n == 5 || n == 13 || n == 31 || n == 49 || n == 81 || n == 113)
    {
        group = 13;
    }
    else if (n == 6 || n == 14 || n == 32 || n == 50 || n == 82 || n == 114)
    {
        group = 14;
    }
    else if (n == 7 || n == 15 || n == 33 || n == 51 || n == 83 || n == 115)
    {
        group = 15;
    }
    else if (n == 8 || n == 16 || n == 34 || n == 52 || n == 84 || n == 116)
    {
        group = 16;
    }
    else if (n == 9 || n == 17 || n == 35 || n == 53 || n == 85 || n == 117)
    {
        group = 17;
    }
    else if (n == 2 || n == 10 || n == 18 || n == 36 || n == 54 || n == 86 || n == 118)
    {
        group = 18;
    }
    return group;
}
char atomic_class(int i)
{
    char ch = ' ';
    int n = i + 1;
    if (n == 1 || n == 3 || n == 11 || n == 19 || n == 37 || n == 55 || n == 87)
    {
        ch = 'a';
    }
    else if (n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        ch = 'b';
    }
    else if (n >= 57 && n <= 71)
    {
        ch = 'c';
    }
    else if (n >= 89 && n <= 103)
    {
        ch = 'd';
    }
    else if ((n >= 21 && n <= 30) || (n >= 39 && n <= 48) || (n >= 72 && n <= 80) || (n >= 104 && n <= 108))
    {
        ch = 'e';
    }
    else if (n == 13 || n == 31 || n == 49 || n == 50 || n >= 81 && n <= 84)
    {
        ch = 'f';
    }
    else if (n >= 6 && n <= 9 || n >= 15 && n <= 17 || n == 34 || n == 35 || n == 53)
    {
        ch = 'g';
    }
    else if (n == 2 || n == 10 || n == 18 || n == 36 || n == 54 || n == 86 || n == 118)
    {
        ch = 'h';
    }
    else
    {
        ch = 'i';
    }

    return ch;
}

void display(int i, char ch1, char ch2, char ch3, char ch4, char ch5)
{
    printf("\t\t\t*******************************Here is your result*****************************************\n");
    printf("\t\t\t___________________________________________________________________________________________\n\n");
    printf("\t\t\t\t\t\tThe atomic number is : %d\n", (i + 1));
    printf("\t\t\t\t\t\tAtomic symbol is %.2s\n", at_symbols[i]);
    printf("\t\t\t\t\t\tAtomic name is %s\n", atoms[i]);
    printf("\t\t\t\t\t\tAtomic Weight is %.2f\n", at_weight[i]);
    printf("\t\t\t\t\t\tThe electronic configuration of the element is :(%s)\n", elec_config[i]);
    printf("\t\t\t\t\t\tThe block is %c\n", ch1);
    printf("\t\t\t\t\t\tThe period of the element is %d\n", ch3);
    printf("\t\t\t\t\t\tThe group of the element is %d\n", ch4);
    printf("\t\t\t\t\t\tThe year of discovery of the element is: %s\n", year_of_discovery[i]);
    fflush(stdin);
    printf("(");
    printf("\t\t\t\t\t\tThe oxidation states of the element is: %s\n", oxidation_state[i]);
    printf(")");
    printf("\t\t\t\t\t\tThe state of existence of the element is: %s\n", atomic_state[i]);

    printf("\t\t\t\t\t\tThe class of the element is :");

    if (ch5 == 'a')
    {
        printf("Alkali Metals\n");
    }
    else if (ch5 == 'b')
    {
        printf("Alkaline Earth Metals\n");
    }
    else if (ch5 == 'c')
    {
        printf("Lanthanoids\n");
    }
    else if (ch5 == 'd')
    {
        printf("\t\t\t\t\t\tActinoids\n");
    }
    else if (ch5 == 'e')
    {
        printf("Transition Metals\n");
    }
    else if (ch5 == 'f')
    {
        printf("Post Transition Metals\n");
    }
    else if (ch5 == 'g')
    {
        printf("Reactive Non Metals\n");
    }
    else if (ch5 == 'h')
    {
        printf("Noble Gases\n");
    }
    else if (ch5 == 'i')
    {
        printf("Metalloid");
    }

    printf("\t\t\t\t\t\tThe Metallic Property is:");
    if (ch2 == 'n')
    {
        printf("Non-metal\n");
    }
    else if (ch2 == 'm')
    {
        printf("Metal\n");
    }
    else if (ch2 == 'x')
    {
        printf("Metalloid\n");
    }
    printf("The recent use of  %s is:--->\n%s\n\n\n\n", atoms[i], recent_use[i]);
}
