PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//629302/1061851/2.49/2/0/Capacitor

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "c140_h90"
		(holeDiam 0.9)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 1.400) (shapeHeight 1.400))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 1.400) (shapeHeight 1.400))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "890334024005" (originalName "890334024005")
		(multiLayer
			(pad (padNum 1) (padStyleRef c140_h90) (pt 0.000, 0.000) (rotation 90))
			(pad (padNum 2) (padStyleRef c140_h90) (pt 12.500, 0.000) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 6.250, 0.000) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.25 5) (pt 13.75 5) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 13.75 5) (pt 13.75 -5) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 13.75 -5) (pt -1.25 -5) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.25 -5) (pt -1.25 5) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.25 5) (pt 13.75 5) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 13.75 5) (pt 13.75 -5) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 13.75 -5) (pt -1.25 -5) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.25 -5) (pt -1.25 5) (width 0.2))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.25 6) (pt 14.75 6) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 14.75 6) (pt 14.75 -6) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 14.75 -6) (pt -2.25 -6) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.25 -6) (pt -2.25 6) (width 0.1))
		)
	)
	(symbolDef "890334024005" (originalName "890334024005")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -35 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 500 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 500 mils -35 mils) (rotation 0]) (justify "UpperRight") (textStyleRef "Normal"))
		))
		(line (pt 220 mils 100 mils) (pt 220 mils -100 mils) (width 6 mils))
		(line (pt 280 mils 100 mils) (pt 280 mils -100 mils) (width 6 mils))
		(line (pt 200 mils 0 mils) (pt 220 mils 0 mils) (width 6 mils))
		(line (pt 280 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 350 mils 250 mils) (justify 24) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 350 mils 150 mils) (justify 24) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "890334024005" (originalName "890334024005") (compHeader (numPins 2) (numParts 1) (refDesPrefix C)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "890334024005"))
		(attachedPattern (patternNum 1) (patternName "890334024005")
			(numPads 2)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
			)
		)
		(attr "Manufacturer_Name" "Wurth Elektronik")
		(attr "Manufacturer_Part_Number" "890334024005")
		(attr "Mouser Part Number" "710-890334024005")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Wurth-Elektronik/890334024005?qs=pceeu5JH%2FH931a333DfnpQ%3D%3D")
		(attr "Arrow Part Number" "")
		(attr "Arrow Price/Stock" "")
		(attr "Mouser Testing Part Number" "")
		(attr "Mouser Testing Price/Stock" "")
		(attr "Description" "Wurth Elektronik 470nF Polypropylene Capacitor PP 310V ac +/-10% Tolerance WCAP-FTXX Series")
		(attr "<Hyperlink>" "https://katalog.we-online.de/pbs/datasheet/890334024005.pdf")
		(attr "<Component Height>" "16.5")
		(attr "<STEP Filename>" "890334024005.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
