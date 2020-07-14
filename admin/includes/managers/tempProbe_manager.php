<?php
require_once __DIR__.'/manager.php';
require_once __DIR__.'/../models/tempProbe.php';

class TempProbeManager extends Manager{
	
	protected function getPrimaryKeys(){
		return ["id"];
	}
	protected function getColumns(){
		return ["name", "type", "pin", "manualAdj", "notes"];
	}
	protected function getTableName(){
		return "tempProbes";
	}
	protected function getDBObject(){
		return new TempProbe();
	}
	protected function getActiveColumnName(){
	    return "active";
	}	
	
	function get_lastAvgTemp(){
        $sql="SELECT AVG(temp) AS AVGTemp, MAX(takenDate) AS takenDate FROM tempLog WHERE takenDate = (SELECT MAX(takenDate) FROM tempLog)";
        return $this->executeNonObjectQueryWithArrayResults($sql)[0];
	}
	function get_lastTemp(){
        $sql="SELECT tp.temp, tp.tempUnit, tn.notes as probe, tp.takenDate from tempProbes tn LEFT OUTER JOIN (SELECT tt.temp, tt.tempUnit, tt.probe, tt.takenDate FROM tempLog tt INNER JOIN (SELECT probe, MAX(takenDate) AS MaxDateTime     FROM tempLog   GROUP BY probe) groupedtt  ON tt.probe = groupedtt.probe  AND tt.takenDate = groupedtt.MaxDateTime) tp ON tp.probe = tn.name;";
        return $this->executeNonObjectQueryWithArrayResults($sql);
	}
}
