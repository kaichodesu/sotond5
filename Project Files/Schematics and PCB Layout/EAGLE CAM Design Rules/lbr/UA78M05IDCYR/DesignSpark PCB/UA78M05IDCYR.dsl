SamacSys ECAD Model
381119/1061851/2.49/4/3/Power Supply

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r175_95"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.95) (shapeHeight 1.75))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r320_175"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.75) (shapeHeight 3.2))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "SOT230P700X180-4N" (originalName "SOT230P700X180-4N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r175_95) (pt -3.15, 2.3) (rotation 90))
			(pad (padNum 2) (padStyleRef r175_95) (pt -3.15, 0) (rotation 90))
			(pad (padNum 3) (padStyleRef r175_95) (pt -3.15, -2.3) (rotation 90))
			(pad (padNum 4) (padStyleRef r320_175) (pt 3.15, 0) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -4.275 3.6) (pt 4.275 3.6) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 4.275 3.6) (pt 4.275 -3.6) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 4.275 -3.6) (pt -4.275 -3.6) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -4.275 -3.6) (pt -4.275 3.6) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.75 3.25) (pt 1.75 3.25) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.75 3.25) (pt 1.75 -3.25) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.75 -3.25) (pt -1.75 -3.25) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.75 -3.25) (pt -1.75 3.25) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.75 0.95) (pt 0.55 3.25) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.75 3.25) (pt 1.75 3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.75 3.25) (pt 1.75 -3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.75 -3.25) (pt -1.75 -3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.75 -3.25) (pt -1.75 3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4.025 3.125) (pt -2.275 3.125) (width 0.2))
		)
	)
	(symbolDef "UA78M05IDCYR" (originalName "UA78M05IDCYR")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 4) (pt 1500 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1270 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 1300 mils 100 mils) (width 6 mils))
		(line (pt 1300 mils 100 mils) (pt 1300 mils -300 mils) (width 6 mils))
		(line (pt 1300 mils -300 mils) (pt 200 mils -300 mils) (width 6 mils))
		(line (pt 200 mils -300 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1350 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "UA78M05IDCYR" (originalName "UA78M05IDCYR") (compHeader (numPins 4) (numParts 1) (refDesPrefix PS)
		)
		(compPin "1" (pinName "INPUT") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "COMMON_1") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "OUTPUT") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "4" (pinName "COMMON_2") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "UA78M05IDCYR"))
		(attachedPattern (patternNum 1) (patternName "SOT230P700X180-4N")
			(numPads 4)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
			)
		)
		(attr "Mouser Part Number" "595-UA78M05IDCYR")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/UA78M05IDCYR?qs=0O%2FZFlpUpJXf0Y5v1qo1ow%3D%3D")
		(attr "Manufacturer_Name" "Texas Instruments")
		(attr "Manufacturer_Part_Number" "UA78M05IDCYR")
		(attr "Description" "500-mA, 25-V, Linear Voltage Regulators")
		(attr "Datasheet Link" "http://www.ti.com/lit/gpn/ua78m")
		(attr "Height" "1.8 mm")
	)

)
