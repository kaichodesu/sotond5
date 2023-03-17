**************************************************
Manufacturer:           Wurth Elektronik 
Contact:                libraries@we-online.com
**************************************************
BEFORE INSTALLING:
Please recognize that the LTspice installation and updates already include many built-in components, including most of our offered models.

* Standard inductor models are included in the LTspice inductor database. Insert the generic inductor symbol (shortcut 'L'), and 
	right-click on the symbol to select an inductor from the database.

* Standard capacitor models are included in the LTspice capacitor database. Insert the generic capacitor symbol (shortcut 'C'), and 
	right-click on the symbol to select a capacitor from the database.

* Standard ferrite beads are included in the LTspice ferrite bead database. Insert component (shortcut 'F2'), select ferrite bead, and 
	place the ferrite bead symbol. Then right-click on the symbol to select a ferrite bead from the database.

* Other models are included in the Contributors folder.  Insert component (shortcut 'F2'), and navigate to folder [Contrib], [Wurth] and then find by product type.

******************************************************************************************************************************************
INSTRUCTIONS:
Copy the library netlist files from "sub" to the user folder  …\Documents\LTspiceXVII\lib\sub\

Copy the symbol files from "sym" to the user folder  …\Documents\LTspiceXVII\lib\sym\

If the LTspice software is open during the copy process, it must be re-started to add the new symbols to the cache. 

******************************************************************************************************************************************
NOTE:
The symbol file references the library netlist file, NOT the netlist file to the symbol file. 
 
* Therefore the contents of the "sym" folder can be arranged in folders according to the user's preference.

* However, the "sub" files CANNOT be nested within subfolders, without first changing the library reference in the relevant symbol files (.asy files).

******************************************************************************************************************************************
DISCLAIMER:
While Würth Elektronik eiSos has made every reasonable effort to ensure the accuracy
of the simulation models provided, Würth Elektronik eiSos does not guarantee the exemption of error on
the simulation models, nor does Würth Elektronik eiSos guarantee that the simulation model is current.
Würth Elektronik eiSos reserves the right to make any adjustments at any time without notice.
Würth Elektronik eiSos expressly disclaims all implied warranties regarding this simulation model.
